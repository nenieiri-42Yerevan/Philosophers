/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:32:03 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/08 17:50:53 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	smart_sleep(long long time, struct s_state *state)
{
	long long	i;

	i = timestamp();
	(void)state;
	while (1)
	{
		if ((timestamp() - i) >= time)
			break ;
	}
}
