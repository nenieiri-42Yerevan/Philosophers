/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:15:42 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/09 19:39:07 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	all_ate(int	*eat_finish, t_philo **philo, int i)
{
	if (philo[0]->state->nb_eat != -1 && \
			philo[i]->ate_count >= philo[0]->state->nb_eat)
		++(*eat_finish);
}

void	*death_checker(void *args)
{
	int		i;
	int		eat_finish;
	t_philo	**philo;

	philo = (t_philo **)args;
	while (1)
	{
		eat_finish = 0;
		i = -1;
		while (++i < philo[0]->state->nb)
		{
			if ((timestamp() - philo[i]->last_meal) > \
				philo[0]->state->time_to_die && philo[i]->philo_born_time != 0)
			{
				philo[i]->is_dead = 1;
				action_print(philo[i], "died");
				eat_finish = -1;
				break ;
			}
			all_ate(&eat_finish, philo, i);
		}
		if (eat_finish == philo[0]->state->nb || eat_finish == -1)
			break ;
	}
	return (0);
}
