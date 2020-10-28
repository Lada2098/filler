/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:58:39 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 14:58:41 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_in_base(char c, char base)
{
	if (base <= 10)
	{
		return (((c >= '0') && (c <= '0' + base - 1)) ? c - '0' : -1);
	}
	if (c >= '0' && c <= '9')
	{
		return (c - '0');
	}
	if ((c >= 'A') && (c <= 'A' + base - 11))
	{
		return (c - 'A' + 10);
	}
	if ((c >= 'a') && (c <= 'a' + base - 11))
	{
		return (c - 'a' + 10);
	}
	return (-1);
}

int			ft_atoi_base(const char *str, char base)
{
	size_t	i;
	int		digit;
	int		res;
	int		negative;

	negative = 1;
	res = 0;
	i = 0;
	while (ft_is_blank(str[i]))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((digit = c_in_base(str[i], base)) >= 0)
	{
		res = res * base + digit;
		i++;
	}
	return (res * negative);
}
