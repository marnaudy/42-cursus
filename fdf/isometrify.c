/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometrify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:36:28 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/15 08:15:46 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void	isometrify_one(t_point *point)
{
	double	x;
	double	y;
	double	z;
	double	alpha;

	alpha = atan(M_SQRT1_2);
	x = point->x;
	y = point->y;
	z = point->z;
	point->x = M_SQRT1_2 * (x - z);
	point->y = y * cos(alpha) - (x + z) * M_SQRT1_2 * sin(alpha);
	point->z = y * sin(alpha) + (x + z) * M_SQRT1_2 * cos(alpha);
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
