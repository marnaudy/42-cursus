/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:11:28 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/16 11:03:50 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	exit_display(t_fdf *data, int ret)
{
	if (data->mlx && data->mlx_win && data->img.ptr)
		mlx_destroy_image(data->mlx, data->img.ptr);
	if (data->mlx && data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free_data(data);
	exit(ret);
	return (ret);
}

int	update_display(t_fdf *data, int reset_zoom)
{
	mlx_destroy_image(data->mlx, data->img.ptr);
	data->img.ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.ptr)
		exit_display(data, 1);
	data->img.addr
		= mlx_get_data_addr(data->img.ptr, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
		exit_display(data, 1);
	transform_all(data);
	if (reset_zoom)
		position_window(data);
	project(data);
	draw_all_lines(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.ptr, 0, 0);
	return (0);
}

void	reset_move(t_fdf *data)
{
	data->move.right = 0;
	data->move.up = 0;
	data->move.rot = 0;
}

int	deal_key(int keycode, t_fdf *data)
{
	if (keycode == 65307)
		exit_display(data, 0);
	else if (keycode == 97)
		data->move.right += data->px_size * 100 * data->camera_z;
	else if (keycode == 100)
		data->move.right -= data->px_size * 100 * data->camera_z;
	else if (keycode == 119)
		data->move.up -= data->px_size * 100 * data->camera_z;
	else if (keycode == 115)
		data->move.up += data->px_size * 100 * data->camera_z;
	else if (keycode == 113)
		data->move.rot--;
	else if (keycode == 101)
		data->move.rot++;
	else if (keycode == 114)
		reset_move(data);
	else
		return (0);
	if (update_display(data, keycode == 114))
		exit_display(data, 1);
	return (0);
}

int	deal_mouse(int button, int x, int y, t_fdf *data)
{
	(void) x;
	(void) y;
	if (button == 4)
		data->px_size *= 1.25;
	else if (button == 5)
		data->px_size *= 0.8;
	else
		return (0);
	if (update_display(data, 0))
		exit_display(data, 0);
	return (0);
}
