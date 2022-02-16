/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:33:18 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/15 08:53:14 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_data(t_fdf *data)
{
	int	i;

	if (!data)
		return ;
	i = 0;
	while (i < data->nb_lin)
	{
		if (data->points)
			free(data->points[i]);
		if (data->display)
			free(data->display[i]);
		i++;
	}
	free(data->mlx);
	free(data->points);
	free(data->display);
	free(data);
}

void	free_text_list(t_text_list *list)
{
	t_text_list	*to_free;

	while (list)
	{
		to_free = list;
		list = list->next;
		free(to_free->text);
		free(to_free);
	}
}

void	free_text_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_all(t_fdf *data, t_text_list *text_list)
{
	free_data(data);
	free_text_list(text_list);
}
