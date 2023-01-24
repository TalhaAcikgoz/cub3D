#include "../inc/cub3d.h"

int draw_line(void *mlx, void *win, int bx, int by, int ex, int ey, int color)
{
    double dx = ex - bx;
    double dy = ey - by;
    int pixels = sqrt((dx * dx) + (dy * dy));
    dx /= pixels;
    dy /= pixels;
    double pixelX = bx;
    double pixelY = by;
    while (pixels)
    {
        mlx_fast_put(&c.img, pixelX, pixelY, 0x00DF349B);
        pixelX += dx;
        pixelY += dy;
        pixels--;
    }
}

int hookee(int kcode, t_main *c)
{
	printf("kcode:%d\n", kcode);
	if (kcode == 119){
		c->p.pos.x+= c->p.delta.x / deltamulti;
		c->p.pos.y+= c->p.delta.y / deltamulti;
	}
	//w
	else if (kcode == 115){
		c->p.pos.x-= c->p.delta.x / deltamulti;
		c->p.pos.y-= c->p.delta.y / deltamulti;
	}
	//s
	else if (kcode == 97){
		c->p.angle -= 0.1;
		if (c->p.angle < 0)
		{
			c->p.angle += 2*PI;
		}
		c->p.delta.x = cos(c->p.angle) * 5;
		c->p.delta.y = sin(c->p.angle) * 5;
		printf(" A dx:%d dy:%d a:%d\n", c->p.delta.x, c->p.delta.y, c->p.angle);
	}
	else if (kcode == 100){
		c->p.angle += 0.1;
		if (c->p.angle < 2 * PI)
		{
			c->p.angle -= 2*PI;
		}
		c->p.delta.x = cos(c->p.angle) * deltamulti;
		c->p.delta.y = sin(c->p.angle) * deltamulti;
		printf(" D dx:%d dy:%d a:%d\n", c->p.delta.x, c->p.delta.y, c->p.angle);
	}
	else if (kcode == 65307){
		mlx_destroy_window(c->mlx, c->window);
		exit(1);
	}
	return 0;
}