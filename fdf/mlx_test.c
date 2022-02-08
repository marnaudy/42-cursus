#include <mlx.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello world!");
	mlx_string_put(mlx_ptr, win_ptr, 10, 10, 0xFF00FF00, "Hello world");
	mlx_loop(mlx_ptr);
}
