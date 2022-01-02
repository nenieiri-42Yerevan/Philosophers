/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:47:20 by vismaily          #+#    #+#             */
/*   Updated: 2022/01/02 18:20:06 by vismaily         ###   ########.fr       */
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

static int	errors(int n)
{
	if (n == 1)
		printf("Arguments count must be 4 or 5\n");
	else if (n == 2)
		printf("Wrong number of philosophers\n");
	else if (n == 3)
		printf("Error: time to die\n");
	else if (n == 4)
		printf("Error: time to eat\n");
	else if (n == 5)
		printf("Error: time to sleep\n");
	else if (n == 6)
		printf("Wrong number of meals\n");
	else if (n == 7)
		printf("Error when initializing mutex\n");
	return (1);
}

int	init_args(int argc, char **argv, struct s_state *state)
{
	if (argc < 5 || argc > 6)
		return (errors(1));
	state->nb = ft_atoi(argv[1]);
	if (state->nb < 2)
		return (errors(2));
	state->t_die = ft_atoi(argv[2]);
	if (state->t_die <= 0)
		return (errors(3));
	state->t_eat = ft_atoi(argv[3]);
	if (state->t_eat <= 0)
		return (errors(4));
	state->t_sleep = ft_atoi(argv[4]);
	if (state->t_sleep <= 0)
		return (errors(5));
	if (argc == 6)
	{
		state->nb_eat = ft_atoi(argv[5]);
		if (state->t_sleep <= 0)
			return (errors(6));
	}
	else
		state->nb_eat = -1;
	state->finish = 0;
	state->all_ate = 0;
	return (0);
}

int	init_philo(struct s_state *state)
{
	int	i;

	state->philo = malloc(state->nb * sizeof(t_philo));
	state->fork = malloc(state->nb * sizeof(pthread_mutex_t));
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
