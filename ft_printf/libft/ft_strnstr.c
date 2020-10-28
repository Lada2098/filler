/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:13:23 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:13:25 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*str;
	char			*find;
	int				l;
	int				i;

	i = 0;
	str = (char *)haystack;
	find = (char *)needle;
	if (!*find)
		return (str);
	l = ft_strlen(find);
	while (*str && i <= ((int)len - l))
	{
		if (ft_strncmp(str, find, l) == 0)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
