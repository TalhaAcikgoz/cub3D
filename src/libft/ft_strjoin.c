/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:03:23 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:03:24 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		index;
	int		s1len;

	if (!s1 || !s2)
		return (NULL);
	index = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (index + 1));
	if (!(ret))
		return (0);
	index = 0;
	while (s1[index] != '\0')
	{
		ret[index] = s1[index];
		index++;
	}
	s1len = index;
	while (s2[index - s1len] != '\0')
	{
		ret[index] = s2[index - s1len];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1 = "ahmet";
	char	*s2 = " eryilmaz";
	char	*s3 = ft_strjoin(s1, s2);

	printf("%s + %s -> %s", s1, s2, s3);
}
*/
