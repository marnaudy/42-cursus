/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:32:18 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/15 15:06:25 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_img_data *data, int x, int y, int colour)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

static int	line_is_horizontal(t_2d_point *line_start,
	t_2d_point *line_end, int *inc)
{
	int	x_diff;
	int	y_diff;
	int	x_dir;
	int	y_dir;

	x_diff = line_end->x - line_start->x;
	x_dir = 1;
	if (x_diff < 0)
		x_dir = -1;
	if (x_diff == 0)
		x_dir = 0;
	x_diff *= x_dir;
	y_diff = line_end->y - line_start->y;
	y_dir = 1;
	if (y_diff < 0)
		y_dir = -1;
	if (y_diff == 0)
		y_dir = 0;
	y_diff *= y_dir;
	if (x_diff >= y_diff)
		*inc = x_dir;
	else
		*inc = y_dir;
	return (x_diff >= y_diff);
}

static int	calculate_line_coord(t_2d_point *line_start,
	t_2d_point *line_end, int x, int is_horizontal)
{
	double	slope;
	int		y;

	if (is_horizontal)
	{
		if (line_end->x - line_start->x == 0)
			return (line_start->y);
		slope = (double)(line_end->y - line_start->y)
			/ (line_end->x - line_start->x);
		y = line_start->y + round(slope * (x - line_start->x));
	}
	else
	{
		slope = (double)(line_end->x - line_start->x)
			/ (line_end->y - line_start->y);
		y = line_start->x + round(slope * (x - line_start->y));
	}
	return (y);
}

static void	draw_line(t_img_data *data, t_2d_point *line_start,
	t_2d_point *line_end, int colour)
{
	int	x;
	int	y;
	int	inc;

	my_mlx_pixel_put(data, line_start->x, line_start->y, colour);
	if (line_is_horizontal(line_start, line_end, &inc))
	{
		x = line_start->x;
		while (x != line_end->x)
		{
			x += inc;
			y = calculate_line_coord(line_start, line_end, x, 1);
			my_mlx_pixel_put(data, x, y, colour);
		}
	}
	else
	{
		y = line_start->y;
		while (y != line_end->y)
		{
			y += inc;
			x = calculate_line_coord(line_start, line_end, y, 0);
			my_mlx_pixel_put(data, x, y, colour);
		}
	}
}

void	draw_all_lines(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_lin)
	{
		j = 0;
		while (j < data->nb_col)
		{
			if (i + 1 < data->nb_lin)
				draw_line(&data->img, &data->display[i][j],
					&data->display[i + 1][j], COLOUR);
			if (j + 1 < data->nb_col)
				draw_line(&data->img, &data->display[i][j],
					&data->display[i][j + 1], COLOUR);
			j++;
		}
		i++;
	}
}
