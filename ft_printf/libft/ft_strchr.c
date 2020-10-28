/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:08:56 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:08:59 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;
	char	cc;

	cc = (char)c;
	str = (char *)s;
	i = 1;
	while (*str && *str != cc)
	{
		str++;
		s++;
		i++;
	}
	if (*str == cc)
		return ((char *)s);
	return (NULL);
}
