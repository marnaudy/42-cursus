/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:03:32 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/16 15:08:25 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# define WIN_HEIGHT 1000
# define WIN_WIDTH 1000
# define WIN_MARGIN 0
# define COLOUR 0X00FFFFFF
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

typedef struct s_one_point
{
	double	x;
	double	y;
	double	z;
}	t_one_point;

typedef struct s_point
{
	t_one_point	old;
	t_one_point	new;
}	t_point;

enum e_projection
{
	isometric,
	parallel,
	perspective
};

typedef struct s_move
{
	int		rot;
	double	right;
	double	up;
}	t_move;

typedef struct s_values
{
	double	cos_a;
	double	sin_a;
	double	cos_b;
	double	sin_b;
}	t_values;

typedef struct s_fdf
{
	t_point				**points;
	t_2d_point			**display;
	char				*name;
	int					nb_lin;
	int					nb_col;
	void				*mlx;
	void				*mlx_win;
	enum e_projection	projection;
	t_move				move;
	t_values			val;
	double				y_adj;
	double				px_size;
	double				camera_z;
	t_img_data			img;
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
int		parse_args(t_fdf *data, int argc, char **argv);
int		parse_file(t_fdf *data, t_text_list *line_list);
t_fdf	*parse(int argc, char **argv);
void	transform_all(t_fdf *data);
void	position_window(t_fdf *data);
void	project(t_fdf *data);
int		is_worth_drawing(t_2d_point *line_start, t_2d_point *line_end);
void	draw_all_lines(t_fdf *data);
int		deal_key(int keycode, t_fdf *data);
int		deal_mouse(int button, int x, int y, t_fdf *data);
int		exit_display(t_fdf *data, int ret);
int		update_display(t_fdf *data, int reset_zoom);
int		display(t_fdf *data);

#endif
