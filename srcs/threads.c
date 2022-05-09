/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:57:12 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/09 15:42:53 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&(philo->state->fork[philo->fork_l]));
	action_print(philo, "has taken a left fork");
	pthread_mutex_lock(&(philo->state->fork[philo->fork_r]));
	action_print(philo, "has taken a right fork");
	action_print(philo, "is eating");
	philo->last_meal = timestamp();
	smart_sleep(philo->state->time_to_eat, philo->state);
	(philo->ate_count)++;
}

static void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 != 0)
		usleep(15000);
	while (1)
	{
		philo_eats(philo);
		action_print(philo, "is sleeping");
		pthread_mutex_unlock(&(philo->state->fork[philo->fork_l]));
		pthread_mutex_unlock(&(philo->state->fork[philo->fork_r]));
		smart_sleep(philo->state->time_to_sleep, philo->state);
		action_print(philo, "is thinking");
	}
	return (NULL);
}

int	threads(struct s_state *state, t_philo **philo)
{
	int			i;
	pthread_t	dead;

	i = -1;
	pthread_create(&dead, NULL, death_checker, (void *)philo);
	state->starting_time = timestamp();
	while (philo[++i] != 0)
	{
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
