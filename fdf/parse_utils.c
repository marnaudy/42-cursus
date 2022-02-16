/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:03:37 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/16 11:55:17 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	parse_line(t_text_list *line, t_point *points,
	int line_size, int line_nb)
{
	int		i;
	char	**array;

	array = ft_split(line->text, ' ');
	if (!array)
		return (1);
	i = 0;
	while (i < line_size && array[i])
	{
		points[i].x = (double) i;
		points[i].y = (double) ft_atoi(array[i]) / DIV_Y;
		points[i].z = (double) line_nb;
		i++;
	}
	while (i < line_size)
	{
		points[i].x = (double) i;
		points[i].y = 0.0;
		points[i].z = (double) line_nb;
		i++;
	}
	free_text_array(array);
	return (0);
}

static int	nb_col(t_text_list *line_list)
{
	int		count;
	char	**array;

	array = ft_split(line_list->text, ' ');
	if (!array)
		return (0);
	count = 0;
	while (array[count])
		count++;
	free_text_array(array);
	return (count);
}

int	parse_file(t_fdf *data, t_text_list *line_list)
{
	int	i;

	i = 0;
	if (!line_list)
		return (1);
	data->nb_col = nb_col(line_list);
	if (data->nb_col == 0)
		return (1);
	data->points = malloc(sizeof(t_point *) * data->nb_lin);
	if (!data->points)
		return (1);
	i = 0;
	while (i < data->nb_lin)
	{
		data->points[i] = malloc(sizeof(t_point) * data->nb_col);
		if (!data->points[i]
			|| parse_line(line_list, data->points[i], data->nb_col, i))
		{
			data->nb_lin = i;
			return (1);
		}
		line_list = line_list->next;
		i++;
	}
	return (0);
}

int	valid_filename(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strcmp(filename + len - 4, ".fdf"))
		return (0);
	return (1);
}
