/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:13:42 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:13:45 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char cc;

	cc = (char)c;
	if (ft_strchr(s, c) == NULL)
		return (NULL);
	while (*s)
		s++;
	while ((*s != cc))
		s--;
	return ((char *)s);
}
