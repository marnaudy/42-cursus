/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:25:18 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/14 12:28:11 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct timeval	last_meal;
	pthread_mutex_t	meal_mutex;
	int				is_happy;
	pthread_mutex_t	happiness_mutex;
}	t_philo;

typedef struct s_global
{
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	nb_philo;
	int				nb_days;
	pthread_mutex_t	end_mutex;
	int				end_simulation;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	struct timeval	start;
	pthread_mutex_t	print_mutex;
}	t_global;

typedef struct s_philo_arg
{
	t_global		*data;
	unsigned int	philo_nb;
}	t_philo_arg;

enum e_state
{
	fork_pickup,
	eating,
	sleeping,
	thinking,
	dead
};

void		free_struct(t_global *data);
int			ft_strict_pos_atoi(const char *s);
t_global	*parse(int argc, char **argv);
void		destroy_n_philo_mutex(t_global *data, int n1, int n2);
int			init_mutex(t_global *data);
int			init_time(t_global *data);
int			timestamp(t_global *data);
int			time_since_last_meal(t_global *data, unsigned int philo_nb);
int			time_until_death(t_global *data, unsigned int philo_nb);
int			update_last_meal(t_global *data, unsigned int philo_nb);
int			display_state(t_global *data, unsigned int philo_nb,
				enum e_state action);
int			is_the_end(t_global *data);
void		*philo_is_happy(t_global *data, unsigned int philo_nb);
void		*simulate(void *arg);
int			join_threads(t_global *data, t_philo_arg *arg_array,
				int n, int dead_philo);
int			monitor_threads(t_global *data, t_philo_arg *arg_array);
int			launch_threads(t_global *data);

#endif
