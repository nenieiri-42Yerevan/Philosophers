/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:42:41 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/09 15:22:58 by vismaily         ###   ########.fr       */
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
	pthread_t		thread;
	int				id;
	int				ate_count;
	int				fork_l;
	int				fork_r;
	long long		last_meal;
	pthread_mutex_t	*writing;
	struct s_state	*state;
}				t_philo;

struct s_state
{
	int				nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	long long		starting_time;
	pthread_mutex_t	*fork;
};

int			init_args(int argc, char **argv, struct s_state *state);
t_philo		**init_philo(struct s_state *state);
int			errors(int n);
int			threads(struct s_state *state, t_philo **philo);
void		*death_checker(void *args);
long long	timestamp(void);
void		action_print(t_philo *philo, char *str);
void		smart_sleep(long long time, struct s_state *state);

#endif
