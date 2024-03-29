/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:04:41 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:04:42 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

double	dabs(double n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}
