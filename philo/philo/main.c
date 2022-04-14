/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:25:55 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/06 12:11:31 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_global	*data;
	int			ret;

	data = parse(argc, argv);
	if (!data)
		return (1);
	if (init_mutex(data))
	{
		free_struct(data);
		return (1);
	}
	ret = launch_threads(data);
	destroy_n_philo_mutex(data, -1, -1);
	free_struct(data);
	return (ret);
}
