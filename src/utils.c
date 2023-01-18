#include "../inc/cub3d.h"

size_t	ft_strlen(const char *str)
{
	int (i) = 0;

	while (str[i])
		i++;
	return (i);
}

int hookee(int kcode, t_main *c)
{
	if (kcode == 13){
		c->posP.y-=1;
	}
	else if (kcode == 1){
		c->posP.y+=1;
	}
	else if (kcode == 0){
		c->posP.x-=1;
	}
	else if (kcode == 2){
		c->posP.x+=1;
	}
	else if (kcode == 53){
		mlx_destroy_window(c->mlx, c->window);
		exit(1);
	}
	return 0;
}

int exit_on_command()
{
	exit(1);
}