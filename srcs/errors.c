/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:56:12 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/11 16:07:56 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	errors(int n)
{
	if (n == 1)
		printf("\033[31;1mArguments count must be 4 or 5\n");
	else if (n == 2)
		printf("\033[31;1mWrong number of philosophers\n");
	else if (n == 3)
		printf("\033[31;1mError: time to die\n");
	else if (n == 4)
		printf("\033[31;1mError: time to eat\n");
	else if (n == 5)
		printf("\033[31;1mError: time to sleep\n");
	else if (n == 6)
		printf("\033[31;1mWrong number of meals\n");
	else if (n == 7)
		printf("\033[31;1mError when initializing mutex\n");
	return (1);
}
