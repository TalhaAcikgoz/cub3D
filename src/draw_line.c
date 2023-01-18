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