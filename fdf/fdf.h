/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:03:32 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/16 14:45:35 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_HEIGHT 1000
# define WIN_WIDTH 1000
# define WIN_MARGIN 20
# define COLOUR 0X0000FF00
# define DIV_Y 1.0

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

typedef struct s_2d_point
{
	int	x;
	int	y;
}	t_2d_point;

typedef struct s_img_data {
	void	*ptr;
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

typedef struct s_win_size
{
	double	px_size;
	double	x_min;
	double	y_max;
}	t_win_size;

typedef struct s_fdf
{
	t_point		**points;
	t_2d_point	**display;
	char		*name;
	int			nb_lin;
	int			nb_col;
	void		*mlx;
	void		*mlx_win;
	t_win_size	win_size;
	t_img_data	img;
}	t_fdf;

typedef struct s_text_list
{
	char				*text;
	struct s_text_list	*next;
}	t_text_list;

void	free_data(t_fdf *data);
void	free_text_list(t_text_list *list);
void	free_text_array(char **array);
void	free_all(t_fdf *data, t_text_list *text_list);
int		valid_filename(char *filename);
int		parse_file(t_fdf *data, t_text_list *line_list);
t_fdf	*parse(int argc, char **argv);
void	isometrify_all(t_fdf *data);
void	position_window(t_fdf *data);
void	project(t_fdf *data);
void	draw_all_lines(t_fdf *data);
int		display(t_fdf *data);

#endif
