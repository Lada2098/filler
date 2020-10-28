/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:12:23 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:12:26 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*rez;
	size_t	len;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)s;
	len = (size_t)ft_strlen(str);
	if (!(rez = ft_strnew(len)))
		return (NULL);
	while (i < (int)len)
	{
		rez[i] = f(s[i]);
		i++;
	}
	return (rez);
}
