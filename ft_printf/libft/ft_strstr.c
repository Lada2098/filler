/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:14:12 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:14:15 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char			*str;
	char			*find;
	unsigned int	l;

	str = (char *)haystack;
	find = (char *)needle;
	if (!*find)
		return (str);
	l = (unsigned int)ft_strlen(find);
	while (*str)
	{
		if (ft_strncmp(str, find, l) == 0)
			return (str);
		str++;
	}
	return (NULL);
}
