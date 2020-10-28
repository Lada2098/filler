/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_output_type_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:49:20 by gekans            #+#    #+#             */
/*   Updated: 2020/08/16 02:49:24 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_output_type_с(t_printf *pr)
{
	int		n;
	char	value;

	value = (char)va_arg(pr->ap, int);
	n = pr->width - 1;
	if (pr->flag_minus)
	{
		pr_putchar(pr, value);
		pr_putstr_repeat(pr, n, ' ');
	}
	else
	{
		pr_putstr_repeat(pr, n, ' ');
		pr_putchar(pr, value);
	}
}
