/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:37:42 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/16 11:09:16 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	init_display(t_fdf *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_display(data, 1);
	data->mlx_win
		= mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, data->name);
	if (!data->mlx_win)
		exit_display(data, 1);
	data->img.ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.ptr)
		exit_display(data, 1);
	data->img.addr
		= mlx_get_data_addr(data->img.ptr, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
		exit_display(data, 1);
	return (0);
}

int	exit_display_good(t_fdf *data)
{
	if (data->mlx && data->mlx_win && data->img.ptr)
		mlx_destroy_image(data->mlx, data->img.ptr);
	if (data->mlx && data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free_data(data);
	exit(0);
	return (0);
}

static double	center_y(t_fdf *data)
{
	int		i;
	int		j;
	double	y_min;
	double	y_max;

	i = 0;
	y_min = data->points[0][0].old.y;
	y_max = y_min;
	while (i < data->nb_lin)
	{
		j = 0;
		while (j < data->nb_col)
		{
			if (data->points[i][j].old.y > y_max)
				y_max = data->points[i][j].old.y;
			if (data->points[i][j].old.y < y_min)
				y_min = data->points[i][j].old.y;
			j++;
		}
		i++;
	}
	return ((0.0 - y_min - y_max) / 2.0);
}

int	display(t_fdf *data)
{
	if (init_display(data))
		return (1);
	data->y_adj = center_y(data);
	transform_all(data);
	position_window(data);
	project(data);
	draw_all_lines(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.ptr, 0, 0);
	mlx_key_hook(data->mlx_win, deal_key, data);
	mlx_mouse_hook(data->mlx_win, deal_mouse, data);
	mlx_hook(data->mlx_win, 17, 0L, exit_display_good, data);
	mlx_loop(data->mlx);
	return (0);
}
