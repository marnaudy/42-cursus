/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:03:32 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/03 13:03:01 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_HEIGHT 500
# define WIN_WIDTH 500

typedef struct s_2d_point
{
	int	x;
	int	y;
}	t_2d_point;

typedef struct s_line
{
	t_2d_point	start;
	t_2d_point	end;
}	t_line;

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_win_coord
{
	int	x;
	int	y;
}	t_win_coord;

typedef struct s_win_size
{
	double	px_size;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_win_size;

typedef struct s_fdf
{
	t_point		**points;
	t_win_coord	**display;
	int			nb_lin;
	int			nb_col;
	t_win_size	win;
	t_img_data	img;
}	t_fdf;

#endif
