#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "string.h"
# include <math.h>

# ifndef BUFFERSIZE
# define BUFFERSIZE 10
# endif

# define PIXEL  16
# define WIDTH  32*40
# define HEIGHT 32*40
# define PI     3.14159265359
# define ofset  100
# define deltamulti 5

typedef struct s_vector2
{
    int x;
    int y;
}   t_vector2;

typedef struct s_vector2d
{
    double x;
    double y;
}   t_vector2d;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_data;

typedef struct s_player {
    t_vector2d   pos;
    t_vector2d   delta;
    double      angle;
}   t_player;

typedef struct s_main
{
    void        *mlx;
    void        *window;
    char        **map;
    t_data      img;
    t_player    p;
}   t_main;

extern t_main  c;

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int     hookee(int kcode, t_main *c);
int     exit_on_command();
void	getMap(char *path);
int     render(t_data *img);
void    mlx_fast_put(t_data *data, int x, int y, int color);
int     draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);
int game_init(char *path);

#endif