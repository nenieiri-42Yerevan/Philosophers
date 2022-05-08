/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:42:41 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/08 15:56:22 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				ate_count;
	int				fork_l;
	int				fork_r;
	long long		last_meal;
	pthread_t		thread;
	struct s_state	*state;
}				t_philo;

struct s_state
{
	int				nb;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	int				finish;
	int				all_ate;
	long long		starting_time;
	t_philo			*philo;
	pthread_mutex_t	writing;
	pthread_mutex_t	*fork;
};

int			init_args(int argc, char **argv, struct s_state *state);
int			init_philo(struct s_state *state);
int			errors(int n);
int			threads(struct s_state *state);
long long	timestamp(void);
void		action_print(t_philo *philo, char *str);
void		smart_sleep(long long time, struct s_state *state);

#endif
