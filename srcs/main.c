/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:09:08 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/09 15:40:02 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_philos(t_philo **philo)
{
	int	i;

	i = -1;
	free(philo[++i]->state->fork);
	while (philo[i++] != 0)
		free(philo[i]);
	free(philo);
}

int	main(int argc, char **argv)
{
	struct s_state	state;
	t_philo			**philo;

	if (init_args(argc, argv, &state) == 0)
	{
		philo = init_philo(&state);
		if (philo == 0)
			return (0);
		threads(&state, philo);
		free_philos(philo);
	}
	return (0);
}
