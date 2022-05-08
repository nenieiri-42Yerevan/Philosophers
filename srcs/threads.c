/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:57:12 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/08 15:57:46 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&(philo->state->fork[philo->fork_l]));
	action_print(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->state->fork[philo->fork_r]));
	action_print(philo, "has taken a fork");
	action_print(philo, "is eating");
	philo->last_meal = timestamp();
	smart_sleep(philo->state->t_eat, philo->state);
	(philo->ate_count)++;
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 != 0)
		usleep(15000);
	while (philo->state->finish != 1)
	{
		philo_eats(philo);
		action_print(philo, "is sleeping");
		pthread_mutex_unlock(&(philo->state->fork[philo->fork_l]));
		pthread_mutex_unlock(&(philo->state->fork[philo->fork_r]));
		if (philo->state->all_ate == 1)
			break ;
		smart_sleep(philo->state->t_sleep, philo->state);
		action_print(philo, "is thinking");
	}
	return (NULL);
}

void	death_checker(struct s_state *state)
{
	int	i;

	while (!(state->all_ate))
	{
		i = -1;
		while (++i < state->nb && !(state->finish))
		{
			if ((timestamp() - state->philo[i].last_meal) > state->t_die)
			{
				action_print(&(state->philo[i]), "died");
				state->finish = 1;
			}
		}
		if (state->finish)
			break ;
		i = 0;
		while (state->nb_eat != -1 && i < state->nb \
				&& state->philo[i].ate_count >= state->nb_eat)
			i++;
		if (i == state->nb)
			state->all_ate = 1;
	}
}

int	threads(struct s_state *state)
{
	int	i;

	i = 0;
	state->starting_time = timestamp();
	while (i < state->nb)
	{
		if (pthread_create(&(state->philo[i].thread), NULL, \
					routine, (void *)&(state->philo[i])))
			return (1);
		state->philo[i].last_meal = timestamp();
		i++;
	}
	death_checker(state);
	i = 0;
	while (i < state->nb)
		pthread_join(state->philo[i++].thread, NULL);
	i = -1;
	while (++i < state->nb)
		pthread_mutex_destroy(&(state->fork[i]));
	pthread_mutex_destroy(&(state->writing));
	return (0);
}
