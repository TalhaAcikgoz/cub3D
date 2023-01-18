#include "../inc/cub3d.h"

void	set_player_pos()
{
	for (int i=0; c.map[i]; i++) {
		for (int j=0; c.map[i][j]; j++) {
			if (c.map[i][j] == 'N'){
				c.posP.x = j;
				c.posP.y = i;
			}
		}
	}
}

void	getMap(char *path)
{
	int	fd;
	char	*line;

	line = malloc(sizeof(char) * 500);
	fd = open("map/map1.cub", O_RDONLY);
	int i = read(fd, line, 500);
	if (i < 0)
		printf("error\n");
	c.map = ft_split(line, '\n');
	set_player_pos();
}