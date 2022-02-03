/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:02:52 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/03 13:03:26 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fdf.h"

void	isometrify_one(t_point *point)
{
	double	x;
	double	y;
	double	z;
	double	sqrt2_2;
	double	alpha;

	sqrt2_2 = sqrt(2.0) / 2.0;
	alpha = atan(sqrt2_2);
	x = point->x;
	y = point->y;
	z = point->z;
	point->x = x * sqrt2_2 - z * sqrt2_2;
	point->y = (x + y) * sqrt2_2 * sin(alpha) + y * cos(alpha);
	point->z = (x + z) * sqrt2_2 * cos(alpha) - y * sin(alpha);
}

void	isometrify_all(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_lin)
	{
		j = 0;
		while (j < data->nb_col)
		{
			isometrify_one(&data->points[i][j]);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	return (0);
}
