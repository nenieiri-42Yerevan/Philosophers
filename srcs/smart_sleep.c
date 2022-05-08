/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:32:03 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/08 15:54:46 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
