/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:54:09 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/09 15:14:07 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->writing);
	printf("%lld %d %s\n", timestamp() - philo->state->starting_time, \
			philo->id + 1, str);
	pthread_mutex_unlock(philo->writing);
}
