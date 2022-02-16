/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:11:01 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/16 14:46:29 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	find_min_max(t_fdf *data, double *x_max, double *y_min)
{
	int	i;
	int	j;

	i = 0;
	data->win_size.x_min = data->points[0][0].x;
	data->win_size.y_max = data->points[0][0].y;
	*x_max = data->points[0][0].x;
	*y_min = data->points[0][0].y;
	while (i < data->nb_lin)
	{
		j = 0;
		while (j < data->nb_col)
		{
			if (data->points[i][j].x < data->win_size.x_min)
				data->win_size.x_min = data->points[i][j].x;
			if (data->points[i][j].y < *y_min)
				*y_min = data->points[i][j].y;
			if (data->points[i][j].x > *x_max)
				*x_max = data->points[i][j].x;
			if (data->points[i][j].y > data->win_size.y_max)
				data->win_size.y_max = data->points[i][j].y;
			j++;
		}
		i++;
	}
}

void	position_window(t_fdf *data)
{
	double	x_max;
	double	y_min;
	double	y_px_size;

	find_min_max(data, &x_max, &y_min);
	data->win_size.px_size = (x_max - data->win_size.x_min)
		/ (WIN_WIDTH - 2 * WIN_MARGIN);
	y_px_size = (data->win_size.y_max - y_min) / (WIN_HEIGHT - 2 * WIN_MARGIN);
	if (y_px_size > data->win_size.px_size)
		data->win_size.px_size = y_px_size;
	if (data->win_size.px_size == 0.0)
		data->win_size.px_size = 0.0001;
}

void	project(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_lin)
	{
		j = 0;
		while (j < data->nb_col)
		{
			data->display[i][j].x = WIN_MARGIN + round((data->points[i][j].x
						- data->win_size.x_min) / data->win_size.px_size);
			data->display[i][j].y = WIN_MARGIN + round((data->win_size.y_max
						- data->points[i][j].y) / data->win_size.px_size);
			j++;
		}
		i++;
	}
}
