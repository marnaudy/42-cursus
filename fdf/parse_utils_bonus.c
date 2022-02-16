/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:03:37 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/16 12:02:26 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	parse_line(t_text_list *line, t_fdf *data,
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
		data->points[line_nb][i].old.x = (double)(i - data->nb_col / 2);
		data->points[line_nb][i].old.y = (double) ft_atoi(array[i]) / DIV_Y;
		data->points[line_nb][i].old.z = (double)(line_nb - data->nb_lin / 2);
		i++;
	}
	while (i < line_size)
	{
		data->points[line_nb][i].old.x = (double)(i - data->nb_col / 2);
		data->points[line_nb][i].old.y = 0.0;
		data->points[line_nb][i].old.z = (double)(line_nb - data->nb_lin / 2);
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
			|| parse_line(line_list, data, data->nb_col, i))
		{
			data->nb_lin = i + 1;
			return (1);
		}
		line_list = line_list->next;
		i++;
	}
	return (0);
}

int	parse_args(t_fdf *data, int argc, char **argv)
{
	if (argc > 3)
	{
		free_data(data);
		return (1);
	}
	if (argc == 2)
		data->projection = isometric;
	else if (!ft_strcmp(argv[2], "isometric"))
		data->projection = isometric;
	else if (!ft_strcmp(argv[2], "parallel"))
		data->projection = parallel;
	else if (!ft_strcmp(argv[2], "perspective"))
		data->projection = perspective;
	else
	{
		free_data(data);
		return (1);
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
