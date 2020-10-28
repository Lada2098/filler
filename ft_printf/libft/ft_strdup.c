/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:10:32 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:10:34 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*rez;
	int		l;
	char	*str;

	str = (char *)src;
	l = ft_strlen(src);
	if (!(rez = (char *)malloc(sizeof(char) * l + 1)))
		return (NULL);
	while (*str)
	{
		*rez = *str;
		rez++;
		str++;
	}
	*rez = '\0';
	rez = rez - l;
	return (rez);
}
