/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:36:28 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/15 14:57:51 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	transform_one(t_fdf *data, t_point *point)
{
	double	x;
	double	y;
	double	z;

	x = point->old.x;
	y = point->old.y + data->y_adj;
	z = point->old.z;
	point->new.x = x * data->val.cos_b
		- z * data->val.sin_b + data->move.right;
	point->new.y = y * data->val.cos_a - data->val.sin_a
		* (x * data->val.sin_b + z * data->val.cos_b) + data->move.up;
	point->new.z = y * data->val.sin_a
		+ data->val.cos_a * (x * data->val.sin_b + z * data->val.cos_b);
}

void	transform_all(t_fdf *data)
{
	int		i;
	int		j;
	double	beta;

	if (data->projection == isometric)
		beta = M_PI_4 * (2 * data->move.rot + 1);
	else
		beta = (data->move.rot + 3) * 0.125;
	data->val.cos_b = cos(beta);
	data->val.sin_b = sin(beta);
	i = 0;
	while (i < data->nb_lin)
	{
		j = 0;
		while (j < data->nb_col)
		{
			transform_one(data, &data->points[i][j]);
			j++;
		}
		i++;
	}
}
