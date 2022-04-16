/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:11:42 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/16 18:42:30 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_global	*init(unsigned int nb_philo)
{
	t_global		*new_data;

	new_data = malloc(sizeof(t_global));
	if (!new_data)
		return (NULL);
	new_data->pid = malloc(nb_philo * sizeof(int));
	if (!new_data->pid)
	{
		free(new_data);
		return (NULL);
	}
	new_data->nb_philo = nb_philo;
	new_data->will_to_live = 1;
	new_data->forks = NULL;
	new_data->fork_access = NULL;
	new_data->end_simulation = NULL;
	new_data->last_meal_access = NULL;
	new_data->will_to_live_access = NULL;
	new_data->philo_is_happy = NULL;
	new_data->philo_is_dead = NULL;
	new_data->print_access = NULL;
	return (new_data);
}

static t_global	*arg_error(t_global *data)
{
	write(STDERR_FILENO, "Incorrect arguments\n", 20);
	if (data)
	{
		free(data->pid);
		free(data);
	}
	return (NULL);
}

static int	read_times(t_global *data, char **argv)
{
	int	arg_nb;

	arg_nb = ft_strict_pos_atoi(argv[2]);
	if (arg_nb < 0)
		return (1);
	data->time_die = (unsigned int) arg_nb;
	arg_nb = ft_strict_pos_atoi(argv[3]);
	if (arg_nb < 0)
		return (1);
	data->time_eat = (unsigned int) arg_nb;
	arg_nb = ft_strict_pos_atoi(argv[4]);
	if (arg_nb < 0)
		return (1);
	data->time_sleep = (unsigned int) arg_nb;
	return (0);
}

t_global	*parse(int argc, char **argv)
{
	t_global	*data;
	int			arg_nb;

	if (argc < 5 || argc > 6)
		return (arg_error(NULL));
	arg_nb = ft_strict_pos_atoi(argv[1]);
	if (arg_nb <= 0)
		return (arg_error(NULL));
	data = init((unsigned int) arg_nb);
	if (!data)
		return (NULL);
	if (read_times(data, argv))
		return (arg_error(data));
	if (argc == 6)
	{
		arg_nb = ft_strict_pos_atoi(argv[5]);
		if (arg_nb < 0)
			return (arg_error(data));
		data->nb_days = arg_nb;
	}
	else
		data->nb_days = -1;
	return (data);
}
