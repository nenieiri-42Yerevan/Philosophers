/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:09:08 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/09 16:57:05 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	}
	return (0);
}
