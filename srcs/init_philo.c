/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:57:56 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/09 19:37:49 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_fill(t_philo **philo, int i, struct s_state *state, \
		pthread_mutex_t *writing)
{
	philo[i] = (t_philo *)malloc(sizeof(t_philo));
	if (philo[i] == 0)
		return (0);
	philo[i]->id = i;
	philo[i]->ate_count = 0;
	philo[i]->last_meal = 0;
	philo[i]->is_dead = 0;
	philo[i]->philo_born_time = 0;
	philo[i]->fork_l = i;
	philo[i]->fork_r = (i + 1) % state->nb;
	philo[i]->writing = writing;
	philo[i]->state = state;
	if (pthread_mutex_init(&(state->fork[i]), NULL))
	{
		errors(7);
		return (0);
	}
	return (1);
}

t_philo	**init_philo(struct s_state *state)
{
	int				i;
	t_philo			**philo;
	pthread_mutex_t	writing;

	philo = (t_philo **)malloc(sizeof(t_philo) * (state->nb + 1));
	state->fork = malloc(sizeof(pthread_mutex_t) * state->nb);
	if (!philo || !(state->fork))
		exit(0);
	philo[state->nb] = 0;
	if (pthread_mutex_init(&writing, NULL) != 0)
	{
		errors(7);
		return (0);
	}
	i = -1;
	while (++i < state->nb)
	{
		if (philo_fill(philo, i, state, &writing) == 0)
			return (0);
	}
	return (philo);
}
