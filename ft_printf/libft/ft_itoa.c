/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:01:35 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:01:38 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*keks(int l, long m, long nl, int n)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)ft_memalloc(sizeof(char) * (l + 2))))
		return (NULL);
	if (n < 0)
		str[i++] = '-';
	while (m > 0)
	{
		str[i++] = (nl / m + '0');
		nl = nl % m;
		m = m / 10;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	long	m;
	long	nl;
	int		l;

	m = 1;
	nl = n;
	l = 0;
	if (nl < 0)
	{
		nl = -nl;
		l++;
	}
	while (nl / (m * 10) > 0)
	{
		m = m * 10;
		l++;
	}
	return (keks(l, m, nl, n));
}
