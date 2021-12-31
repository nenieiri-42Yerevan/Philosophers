/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:09:08 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/31 17:11:21 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int init_philo(struct s_state *state)
{
	int	i;

	state->philo = malloc(state->nb * sizeof(t_philo));
	if (!(state->philo))
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < state->nb)
	{
		state->philo[i].id = i;
		state->philo[i].fork_l = i;
		state->philo[i].fork_r = (i + 1) % state->nb;
	}
}

void	*routine(void *args)
{
	struct s_state	*state;

	state = (struct s_state *)args;
	printf("%d\n", state->tmp_nb);
}

int	init_thread(struct s_state *state)
{
	int	i;

	i = 0;
	while (i < state->nb)
	{
		state->tmp_nb = i;
		if (pthread_create(&(state->philo[i].thread), NULL, \
					routine, (void *)state))
			return (1);
		i++;
	}
	i = 0;
	while (i < state->nb)
		pthread_join(state->philo[i++].thread, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_state	state;

	if (init_args(argc, argv, &state) == 0)
	{
		init_philo(&state);
		init_thread(&state);
	}
	return (0);
}
