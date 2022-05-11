/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:54:09 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/11 16:01:31 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_print(t_philo *philo, char *str, char *color)
{
	pthread_mutex_lock(philo->writing);
	printf("%s%lld %d %s\033[0m\n", color, \
			timestamp() - philo->philo_born_time, philo->id + 1, str);
	pthread_mutex_unlock(philo->writing);
}
