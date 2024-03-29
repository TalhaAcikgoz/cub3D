/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:00:13 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:14 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	horizontalcheck(char **map, int i, int j, int flag)
{
	while (map[++i])
	{
		flag = 0;
		j = -1;
		while (map[i][++j])
		{
			if (flag == 0 && map[i][j] == '1')
				flag ^= 1;
			if (flag == 0 && ft_strchr("NSEW0", map[i][j]))
				return (0);
			if (flag == 1 && map[i][j] == ' ')
			{
				if (map[i][j - 1] && ft_strchr("0NSEW", map[i][j - 1]))
					return (0);
				flag ^= 1;
			}
		}
	}
	return (1);
}

static int	verticalcheck(char **map, int i, int j, int flag)
{
	while (map[0][++j])
	{
		flag = 0;
		i = 0;
		while (map[i] && map[i][j])
		{
			if (flag == 0 && map[i][j] == '1')
				flag ^= 1;
			if (flag == 0 && ft_strchr("NSEW0", map[i][j]))
				return (0);
			if (flag == 1 && map[i][j] == ' ')
			{
				if (map[i - 1] && map[i - 1][j]
						&& ft_strchr("0NSEW", map[i - 1][j]))
					return (0);
				flag ^= 1;
			}
			if (!map[i + 1] && ft_strchr("NSEW0", map[i][j]))
				return (0);
			i++;
		}
	}
	return (1);
}

//
//	This hierarchy because 25 line in function rule
//
int	mapcheck(char **map)
{
	if (!horizontalcheck(map, -1, -1, 0))
		return (0);
	if (!verticalcheck(map, -1, -1, 0))
		return (0);
	return (1);
}
