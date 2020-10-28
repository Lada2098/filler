/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:09:08 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:09:10 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr_n(const char *s, int c)
{
	char	*str;
	int		i;
	char	cc;

	cc = (char)c;
	str = (char *)s;
	i = 0;
	while (*str && *str != cc)
	{
		str++;
		s++;
		i++;
	}
	if (*str == cc)
		return (i);
	return (0);
}
