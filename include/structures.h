/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:06:14 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:06:15 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdlib.h>

typedef struct s_vectord
{
	double	x;
	double	y;
}	t_vectord;

typedef struct s_vectori
{
	int	x;
	int	y;
}	t_vectori;

typedef struct s_onkeys
{
	int			keyw;
	int			keya;
	int			keys;
	int			keyd;
	int			keyup;
	int			keydown;
	int			keyleft;
	int			keyright;
	t_vectori	cursorpos;
}	t_onkeys;

typedef struct s_map
{
	char	**map;
	size_t	x;
	size_t	y;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

//	xpm[0] = NO
//	xpm[1] = SO
//	xpm[2] = WE
//	xpm[3] = EA
typedef struct s_textures
{
	int		top;
	int		bot;
	t_data	*xpm[4];
	t_data	*sprite[5];
	t_data	*lastanimation;
}	t_textures;

typedef struct s_chararacter
{
	t_vectord	pos;
	t_vectord	dir;
	t_vectord	plane;
	double		angle;
}	t_character;

typedef struct s_draw
{
	int			wall;
	int			color;
	int			lineheight;
	double		step;
	double		texpos;
	double		wallx;
	double		perpwalldist;
	t_vectori	tex;
	t_vectori	drawwall;
}	t_draw;

typedef struct s_raycast
{
	int			hit;
	int			side;
	t_draw		draw;
	t_vectord	pos;
	t_vectord	dir;
	t_vectord	plane;
	t_vectord	raydir;
	t_vectord	deltadist;
	t_vectord	sidedist;
	t_vectori	step;
	t_vectori	map;
}	t_raycast;

typedef struct s_minimap
{
	t_data	*img;
}	t_minimap;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	size_t		loop;
	t_map		*map;
	t_data		*img;
	t_onkeys	onkey;
	t_minimap	*mmap;
	t_raycast	raycast;
	t_textures	texture;
	t_character	*player;
}	t_cub3d;

#endif
