/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:25:18 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/16 19:02:00 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct s_global
{
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	nb_philo;
	int				nb_days;
	struct timeval	start;
	sem_t			*forks;
	sem_t			*fork_access;
	sem_t			*philo_is_dead;
	sem_t			*philo_is_dying;
	sem_t			*philo_is_happy;
	sem_t			*end_simulation;
	sem_t			*print_access;
	struct timeval	last_meal;
	sem_t			*last_meal_access;
	int				will_to_live;
	sem_t			*will_to_live_access;
	pthread_t		monitor_1;
	pthread_t		monitor_2;
	int				*pid;
}	t_global;

enum e_state
{
	fork_pickup,
	eating,
	sleeping,
	thinking,
	dead
};

enum e_sem_type
{
	last_meal,
	will
};

typedef struct s_global_and_nb
{
	t_global		*data;
	unsigned int	philo_nb;
}	t_global_and_nb;

int			ft_strict_pos_atoi(const char *s);
t_global	*parse(int argc, char **argv);
void		close_global_sem(t_global *data);
void		unlink_global_sem(t_global *data);
int			init_global_sem(t_global *data);
char		*sem_name(unsigned int philo_nb, enum e_sem_type type);
void		close_philo_sem(t_global *data);
void		unlink_philo_sem(t_global *data, unsigned int philo_nb);
int			init_philo_sem(t_global *data, unsigned int philo_nb);
int			init_time(t_global *data);
int			timestamp(t_global *data);
int			time_since_last_meal(t_global *data);
int			time_until_death(t_global *data);
int			update_last_meal(t_global *data);
int			display_state(t_global *data, unsigned int philo_nb,
				enum e_state action);
int			want_to_live(t_global *data);
void		philo_is_happy(t_global *data);
void		simulate(t_global *data, unsigned int philo_nb);
void		*philo_life_monitoring(void	*data_and_nb);
void		*philo_end_simulation_monitoring(void *void_data);
void		launch_philo_threads(t_global *data, unsigned int philo_nb);
void		launch_main_threads(t_global *data);
void		launch_processes(t_global *data);

#endif
