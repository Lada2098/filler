/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:12:56 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:12:59 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*c;
	size_t	i;

	c = dest;
	i = 0;
	while (*src != '\0' && i < n)
	{
		*dest = (char)*src;
		i++;
		src++;
		dest++;
	}
	while (i < n)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	return (c);
}
