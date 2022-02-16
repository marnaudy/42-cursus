/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:54:22 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/16 09:09:18 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define SOFT_LIMIT 100
#define HARD_LIMIT 300

static int	is_roughly_in_frame(t_2d_point *point)
{
	if (point->x < -HARD_LIMIT || point->x > WIN_WIDTH + HARD_LIMIT
		|| point->y < -HARD_LIMIT || point->y > WIN_HEIGHT + HARD_LIMIT)
		return (0);
	if ((point->x < -SOFT_LIMIT || point->x > WIN_WIDTH + SOFT_LIMIT)
		&& (point->y < -SOFT_LIMIT || point->y > WIN_HEIGHT + SOFT_LIMIT))
		return (0);
	return (1);
}

int	is_worth_drawing(t_2d_point *line_start, t_2d_point *line_end)
{
	return (is_roughly_in_frame(line_start) || is_roughly_in_frame(line_end));
}
