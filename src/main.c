#include "../inc/cub3d.h"

t_main	c;











int main(int ac, char **av)
{
	getMap(av[1]);
	c.mlx = mlx_init();
	c.window = mlx_new_window(c.mlx, WIDTH, HEIGHT, "cube3D");
	c.img.img = mlx_new_image(c.mlx, WIDTH, HEIGHT);
	c.img.addr = mlx_get_data_addr(c.img.img, &c.img.bits_per_pixel, &c.img.line_length,
								&c.img.endian);

	// mlx_hook(c.window, 2, 1L<<0, closee, &c);
	mlx_hook(c.window, 2, 1L<<0, hookee, &c);
	mlx_hook(c.window, 17, 0, exit_on_command, NULL);
	mlx_loop_hook(c.mlx, render, &c.img);
	mlx_loop(c.mlx);
}