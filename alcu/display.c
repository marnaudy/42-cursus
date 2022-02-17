/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:20:36 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/13 08:47:25 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static int	get_max_width(t_alcu *data)
{
	int	i;
	int	max_width;

	if (!data)
		return (0);
	max_width = 0;
	i = 0;
	while (i < data->nb_heaps)
	{
		if (data->heaps[i].nb > max_width)
			max_width = data->heaps[i].nb;
		++i;
	}
	return (max_width);
}

int	display(t_alcu *data)
{
	int	i;
	int	max_width;

	if (!data)
		return (1);
	max_width = get_max_width(data);
	i = 0;
	while (i < data->nb_heaps)
	{
		ft_n_putstr(" ", max_width - data->heaps[i].nb);
		ft_n_putstr("| ", data->heaps[i].nb);
		ft_putstr_fd("\n", STDOUT_FILENO);
		++i;
	}
	return (0);
}
