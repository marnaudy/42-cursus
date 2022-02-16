/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:11:01 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/16 08:45:07 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	find_min_max(t_fdf *data, t_one_point *min, t_one_point *max)
{
	int	i;
	int	j;

	i = 0;
	min->x = data->points[0][0].new.x;
	max->x = data->points[0][0].new.x;
	min->y = data->points[0][0].new.y;
	max->y = data->points[0][0].new.y;
	while (i < data->nb_lin)
	{
		j = 0;
		while (j < data->nb_col)
		{
			if (data->points[i][j].new.x < min->x)
				min->x = data->points[i][j].new.x;
			if (data->points[i][j].new.y < min->y)
				min->y = data->points[i][j].new.y;
			if (data->points[i][j].new.x > max->x)
				max->x = data->points[i][j].new.x;
			if (data->points[i][j].new.y > max->y)
				max->y = data->points[i][j].new.y;
			j++;
		}
		i++;
	}
}

void	position_window(t_fdf *data)
{
	t_one_point	min;
	t_one_point	max;
	double		y_px_size;

	find_min_max(data, &min, &max);
	if (data->projection != perspective)
	{
		data->px_size = (max.x - min.x) / (WIN_WIDTH - 2 * WIN_MARGIN);
		y_px_size = (max.y - min.y) / (WIN_HEIGHT - 2 * WIN_MARGIN);
		if (y_px_size > data->px_size)
			data->px_size = y_px_size;
		if (data->px_size == 0.0)
			data->px_size = 0.000001;
	}
	else
	{
		data->px_size = 1.0 / WIN_WIDTH;
		data->camera_z = max.x - min.x;
	}
}

static void	parallel_project(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_lin)
	{
		j = 0;
		while (j < data->nb_col)
		{
			data->display[i][j].x = WIN_MARGIN + WIN_WIDTH / 2
				+ round(data->points[i][j].new.x / data->px_size);
			data->display[i][j].y = WIN_MARGIN + WIN_HEIGHT / 2
				- round(data->points[i][j].new.y / data->px_size);
			j++;
		}
		i++;
	}
}

static void	perspective_project(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_lin)
	{
		j = 0;
		while (j < data->nb_col)
		{
			data->display[i][j].x = WIN_MARGIN + WIN_WIDTH / 2
				+ round(data->points[i][j].new.x / (data->px_size
						* (data->camera_z - data->points[i][j].new.z)));
			data->display[i][j].y = WIN_MARGIN + WIN_HEIGHT / 2
				- round(data->points[i][j].new.y / (data->px_size
						* (data->camera_z - data->points[i][j].new.z)));
			j++;
		}
		i++;
	}
}

void	project(t_fdf *data)
{
	if (data->projection == perspective)
		perspective_project(data);
	else
		parallel_project(data);
}
