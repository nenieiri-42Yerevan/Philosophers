/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:32:03 by vismaily          #+#    #+#             */
/*   Updated: 2022/01/02 18:20:42 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	action_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->state->writing));
	if (!(philo->state->finish))
	{
		printf("%lld ", timestamp() - philo->state->starting_time);
		printf("%d ", philo->id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(philo->state->writing));
}

void	smart_sleep(long long time, struct s_state *state)
{
	long long	i;

	i = timestamp();
	while (!(state->finish))
	{
		if ((timestamp() - i) >= time)
			break ;
	}
}
