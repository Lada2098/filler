/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:12:49 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:12:51 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	int				k1;
	int				k2;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	k1 = 0;
	k2 = 0;
	i = 0;
	while (((*ss1 && *ss2) && (*ss1 == *ss2)) && i++ < n)
	{
		ss1++;
		ss2++;
	}
	k1 = (int)*ss1;
	k2 = (int)*ss2;
	if (k1 < 0)
		k1 = -k1;
	if (k2 < 0)
		k2 = -k2;
	if (i < n)
		return (k1 - k2);
	return (0);
}
