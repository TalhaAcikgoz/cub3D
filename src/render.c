#include "../inc/cub3d.h"

void	mlx_fast_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *img, int x, int y, int color)
{
	for (int i = x; i < x + PIXEL - 1; i++)
		for (int j = y; j < y + PIXEL - 1; j++)
			mlx_fast_put(img, i, j, color);
}

int	render(t_data *img)
{
	for (int i = 0; i < WIDTH; i++)
		for (int j = 0;j < HEIGHT; j++)
			mlx_fast_put(img, i, j, 0x0000CCCC);

	for (int i=0; c.map[i]; i++) {
		for (int j=0; c.map[i][j]; j++) {
			if (c.map[i][j] == '1')
				draw_square(img, (j * PIXEL), (i * PIXEL), 0x00000000);
			else if (c.map[i][j] == '0')
				draw_square(img, (j * PIXEL), (i * PIXEL), 0x00FFFFFF);
			else if (c.map[i][j] == 'N')
				draw_square(img, (j * PIXEL), (i * PIXEL) , 0x00FFFFFF);
		}
	}
	draw_square(img, c.posP.x * PIXEL, c.posP.y * PIXEL, 0x00DF349B);
    draw_line(c.mlx, c.window, c.posP.x * PIXEL + (PIXEL / 2), c.posP.y * PIXEL, c.posP.x * PIXEL + (PIXEL / 2), (c.posP.y * PIXEL) - 20, 0x00DF349B);
	mlx_put_image_to_window(c.mlx, c.window, img->img, 0, 0);
	return (0);
}