#include <math.h>
#include <mlx.h>

#define WIN_HEIGHT 500
#define WIN_WIDTH 500

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_line
{
	t_point	start;
	t_point	end;
}	t_line;

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

int	line_is_horizontal(t_line *line, int *x_dir, int *y_dir)
{
	int	x_diff;
	int	y_diff;

	x_diff = line->end.x - line->start.x;
	*x_dir = 1;
	if (x_diff < 0)
		*x_dir = -1;
	if (x_diff == 0)
		*x_dir = 0;
	x_diff *= *x_dir;
	y_diff = line->end.y - line->start.y;
	*y_dir = 1;
	if (y_diff < 0)
		*y_dir = -1;
	if (y_diff == 0)
		*y_dir = 0;
	y_diff *= *y_dir;
	return (x_diff >= y_diff);
}

int	calculate_line_coord(int x1, int x2, int y1, int y2, int x)
{
	double	slope;
	int		y;

	slope = (double)(y2 - y1) / (x2 - x1);
	y = y1 + round(slope * (x - x1));
	return (y);
}

void	draw_line(t_img_data *data, t_line *line, int colour)
{
	int	x;
	int	y;
	int	x_dir;
	int	y_dir;

	my_mlx_pixel_put(data, line->start.x, line->start.y, colour);
	if (line_is_horizontal(line, &x_dir, &y_dir))
	{
		x = line->start.x;
		while (x != line->end.x)
		{
			x += x_dir;
			y = calculate_line_coord(line->start.x, line->end.x, line->start.y, line->end.y, x);
			my_mlx_pixel_put(data, x, y, colour);
		}
	}
	else
	{
		y = line->start.x;
		while (y != line->end.y)
		{
			y += y_dir;
			x = calculate_line_coord(line->start.y, line->end.y, line->start.x, line->end.x, y);
			my_mlx_pixel_put(data, x, y, colour);
		}
	}
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_img_data	img;
	t_line		line;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	line.start.x = 100;
	line.start.y = 100;
	line.end.x = 400;
	line.end.y = 300;
	draw_line(&img, &line, 0x0000FF00);
	line.start.x = 100;
	line.start.y = 100;
	line.end.x = 250;
	line.end.y = 450;
	draw_line(&img, &line, 0x000000FF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
