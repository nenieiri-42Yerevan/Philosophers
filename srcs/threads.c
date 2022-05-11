/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:57:12 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/11 16:11:13 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&(philo->state->fork[philo->fork_l]));
	action_print(philo, "has taken a left fork", "\033[33;1m");
	pthread_mutex_lock(&(philo->state->fork[philo->fork_r]));
	if (philo->is_dead == 1)
		return (1);
	action_print(philo, "has taken a right fork", "\033[33;1m");
	action_print(philo, "is eating", "\033[35;1m");
	philo->last_meal = timestamp();
	smart_sleep(philo->state->time_to_eat, philo->state);
	(philo->ate_count)++;
	return (0);
}

static void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 != 0)
		usleep(20000);
	while (1)
	{
		if (philo_eats(philo) == 1)
			break ;
		action_print(philo, "is sleeping", "\033[34;1m");
		pthread_mutex_unlock(&(philo->state->fork[philo->fork_l]));
		pthread_mutex_unlock(&(philo->state->fork[philo->fork_r]));
		smart_sleep(philo->state->time_to_sleep, philo->state);
		action_print(philo, "is thinking", "\033[32;1m");
	}
	return (NULL);
}

int	threads(struct s_state *state, t_philo **philo)
{
	int			i;
	pthread_t	dead;

	i = -1;
	pthread_create(&dead, NULL, death_checker, (void *)philo);
	while (philo[++i] != 0)
	{
		philo[i]->philo_born_time = timestamp();
		philo[i]->last_meal = timestamp();
		if (pthread_create(&(philo[i]->thread), 0, routine, (void *)(philo[i])))
			return (1);
	}
	pthread_join(dead, NULL);
	i = -1;
	while (++i < state->nb)
		pthread_mutex_destroy(&(state->fork[i]));
	pthread_mutex_destroy(philo[0]->writing);
	return (0);
}
