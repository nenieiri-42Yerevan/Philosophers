/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:47:20 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/08 13:58:23 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

int	init_args(int argc, char **argv, struct s_state *state)
{
	if (argc < 5 || argc > 6)
		return (errors(1));
	state->nb = ft_atoi(argv[1]);
	if (state->nb < 1)
		return (errors(2));
	state->time_die = ft_atoi(argv[2]);
	if (state->time_die <= 0)
		return (errors(3));
	state->time_eat = ft_atoi(argv[3]);
	if (state->time_eat <= 0)
		return (errors(4));
	state->time_sleep = ft_atoi(argv[4]);
	if (state->time_sleep <= 0)
		return (errors(5));
	if (argc == 6)
	{
		state->nb_eat = ft_atoi(argv[5]);
		if (state->nb_eat <= 0)
			return (errors(6));
	}
	else
		state->nb_eat = -1;
	state->finish = 0;
	state->all_ate = 0;
	return (0);
}
