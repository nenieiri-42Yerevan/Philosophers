/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:54:09 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/08 15:54:37 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
