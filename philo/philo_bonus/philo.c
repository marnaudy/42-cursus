/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:07:06 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/14 08:36:46 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	philo_sleep(t_global *data, unsigned int philo_nb)
{
	if (!want_to_live(data))
		return (-1);
	if (display_state(data, philo_nb, sleeping))
		return (-1);
	usleep(data->time_sleep * 1000);
	return (0);
}

static int	think(t_global *data, unsigned int philo_nb)
{
	int	life_expectancy;

	life_expectancy = time_until_death(data);
	if (life_expectancy < 0 || !want_to_live(data))
		return (-1);
	if (display_state(data, philo_nb, thinking))
		return (-1);
	while (1)
	{
		if (life_expectancy < 20)
			return (0);
		usleep(10000);
		life_expectancy = time_until_death(data);
	}
}

static int	eat(t_global *data, unsigned int philo_nb)
{
	if (!want_to_live(data))
		return (-1);
	if (update_last_meal(data))
		return (-1);
	if (display_state(data, philo_nb, eating))
		return (-1);
	usleep(data->time_eat * 1000);
	if (sem_post(data->forks) || sem_post(data->forks))
		return (-1);
	return (0);
}

static int	try_to_eat(t_global *data, unsigned int philo_nb)
{
	if (!want_to_live(data) || sem_wait(data->fork_access))
		return (-1);
	if (sem_wait(data->forks))
		return (-1);
	if (!want_to_live(data))
		return (-1);
	if (display_state(data, philo_nb, fork_pickup))
		return (-1);
	if (sem_wait(data->forks))
		return (-1);
	sem_post(data->fork_access);
	if (!want_to_live(data))
		return (-1);
	if (display_state(data, philo_nb, fork_pickup))
		return (-1);
	eat(data, philo_nb);
	return (0);
}

void	simulate(t_global *data, unsigned int philo_nb)
{
	int	days;

	days = 0;
	if (data->nb_philo == 0)
		return ;
	if (data->nb_days == 0)
		return (philo_is_happy(data));
	while (1)
	{
		if (try_to_eat(data, philo_nb))
			return ;
		else
			days++;
		if (days == data->nb_days && data->nb_days >= 0)
			return (philo_is_happy(data));
		if (philo_sleep(data, philo_nb)
			|| think(data, philo_nb))
			return ;
	}
}
