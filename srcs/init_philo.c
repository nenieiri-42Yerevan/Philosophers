/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:57:56 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/08 13:58:23 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.c"

int	init_philo(struct s_state *state)
{
	int	i;

	state->philo = malloc(sizeof(t_philo) * state->nb);
	state->fork = malloc(sizeof(pthread_mutex_t) * state->nb);
	if (!(state->philo) || !(state->fork))
		exit(EXIT_FAILURE);
	if (pthread_mutex_init(&(state->writing), NULL))
		return (errors(7));
	i = -1;
	while (++i < state->nb)
	{
		state->philo[i].id = i;
		state->philo[i].ate_count = 0;
		state->philo[i].last_meal = 0;
		state->philo[i].fork_l = i;
		state->philo[i].fork_r = (i + 1) % state->nb;
		state->philo[i].state = state;
		if (pthread_mutex_init(&(state->fork[i]), NULL))
			return (errors(7));
	}
	return (0);
}
