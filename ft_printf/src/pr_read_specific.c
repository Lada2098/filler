/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_read_specific.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 02:06:05 by ayajirob          #+#    #+#             */
/*   Updated: 2020/08/16 00:37:59 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_read_width(t_printf *pr)
{
	pr->width = 0;
	while (*pr->format >= '0' && *pr->format <= '9')
	{
		pr->width = pr->width * 10 + (*pr->format - '0');
		pr->format++;
	}
}

void	pr_read_precision(t_printf *pr)
{
	pr->precision = -1;
	if (*pr->format == '.')
	{
		pr->format++;
		pr->precision = 0;
		while (*pr->format >= '0' && *pr->format <= '9')
		{
			pr->precision = pr->precision * 10 + (*pr->format - '0');
			pr->format++;
		}
	}
}

void	pr_read_length(t_printf *pr)
{
	if (pr->format[0] == 'l' && pr->format[1] == 'l')
	{
		pr->length = LENGTH_LL;
		pr->format += 2;
	}
	else if (pr->format[0] == 'h' && pr->format[1] == 'h')
	{
		pr->length = LENGTH_HH;
		pr->format += 2;
	}
	else if (*pr->format == 'l')
	{
		pr->length = LENGTH_L;
		pr->format++;
	}
	else if (*pr->format == 'L')
	{
		pr->length = LENGTH_BIGL;
		pr->format++;
	}
	else if (*pr->format == 'h')
	{
		pr->length = LENGTH_H;
		pr->format++;
	}
}

void	pr_read_type(t_printf *pr)
{
	pr->type = *pr->format;
	pr->format++;
}

void	pr_read_specific(t_printf *pr)
{
	pr->flag_minus = 0;
	pr->flag_plus = 0;
	pr->flag_hash = 0;
	pr->flag_zero = 0;
	pr->flag_space = 0;
	pr->first_sign = 0;
	pr->format++;
	pr_read_flags(pr);
	pr_read_width(pr);
	pr_read_precision(pr);
	pr->length = LENGTH_DEFAULT;
	pr_read_length(pr);
	pr_read_type(pr);
}
