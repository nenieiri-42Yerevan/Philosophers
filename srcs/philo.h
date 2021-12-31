/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:42:41 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/31 16:37:22 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int			id;
	int			fork_l;
	int			fork_r;
	pthread_t	thread;
}				t_philo;

struct s_state
{
	int		nb;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		nb_eat;
	int		tmp_nb;
	t_philo	*philo;
};

int	init_args(int argc, char **argv, struct s_state *state);

#endif
