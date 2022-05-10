/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:47:20 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/10 15:34:05 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	cmp_chars(char a, char b)
{
	if ((a - b) < 0)
		return (-1);
	else if ((a - b) == 0)
		return (0);
	return (1);
}

static int	cmp(int i, const char *str, int len)
{
	if (len == 11)
		len = 1;
	else
		len = 0;
	if (i == 0)
		return (cmp_chars('2', str[i + len]));
	if (i == 1)
		return (cmp_chars('1', str[i + len]));
	if (i == 2)
		return (cmp_chars('4', str[i + len]));
	if (i == 3)
		return (cmp_chars('7', str[i + len]));
	if (i == 4)
		return (cmp_chars('4', str[i + len]));
	if (i == 5)
		return (cmp_chars('8', str[i + len]));
	if (i == 6)
		return (cmp_chars('3', str[i + len]));
	if (i == 7)
		return (cmp_chars('6', str[i + len]));
	if (i == 8)
		return (cmp_chars('4', str[i + len]));
	if (i == 9)
		return (cmp_chars('7', str[i + len]));
	return (2);
}

static int	check_num(const char *str)
{
	int	i;
	int	res;
	int	len;

	res = 0;
	i = -1;
	while (str[++i] != '\0')
		if (!((str[i] >= '0' && str[i] <= '9') || (i == 0 && str[i] == '+')))
			return (-1);
	if (i > 11)
		return (-1);
	else if ((str[0] != '+' && i == 10) || (str[0] == '+' && i == 11))
	{
		len = i;
		i = -1;
		while (++i < 10)
		{
			res = cmp(i, str, len);
			if (res == -1 || res == 0)
				break ;
		}
	}
	return (res);
}

static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (check_num(str) == -1)
		return (-1);
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
	{
		return (errors(1));
	}
	state->nb = ft_atoi(argv[1]);
	if (state->nb < 1 || state->nb > 200)
		return (errors(2));
	state->time_to_die = ft_atoi(argv[2]);
	if (state->time_to_die <= 0)
		return (errors(3));
	state->time_to_eat = ft_atoi(argv[3]);
	if (state->time_to_eat <= 0)
		return (errors(4));
	state->time_to_sleep = ft_atoi(argv[4]);
	if (state->time_to_sleep <= 0)
		return (errors(5));
	if (argc == 6)
	{
		state->nb_eat = ft_atoi(argv[5]);
		if (state->nb_eat <= 0)
			return (errors(6));
	}
	else
		state->nb_eat = -1;
	return (0);
}
