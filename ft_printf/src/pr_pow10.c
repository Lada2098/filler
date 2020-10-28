/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_pow10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:48:09 by gekans            #+#    #+#             */
/*   Updated: 2020/08/16 02:48:13 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	pr_pow10(int n)
{
	unsigned long long		value;

	value = 1;
	while (n > 0)
	{
		value = value * 10;
		n--;
	}
	return (value);
}
