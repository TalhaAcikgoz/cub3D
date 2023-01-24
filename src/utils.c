#include "../inc/cub3d.h"

size_t	ft_strlen(const char *str)
{
	int (i) = 0;

	while (str[i])
		i++;
	return (i);
}

int exit_on_command()
{
	exit(1);
}