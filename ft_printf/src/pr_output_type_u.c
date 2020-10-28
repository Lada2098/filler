/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_output_type_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:31:08 by ayajirob          #+#    #+#             */
/*   Updated: 2020/08/16 00:39:17 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	pr_read_value_type_u(t_printf *pr)
{
	unsigned long long	value;

	if (pr->length == LENGTH_HH)
		value = (unsigned char)va_arg(pr->ap, unsigned int);
	else if (pr->length == LENGTH_H)
		value = (unsigned short)va_arg(pr->ap, unsigned int);
	else if (pr->length == LENGTH_L)
		value = (unsigned long)va_arg(pr->ap, unsigned long);
	else if (pr->length == LENGTH_LL)
		value = (unsigned long long)va_arg(pr->ap, unsigned long long);
	else
		value = (unsigned int)va_arg(pr->ap, unsigned int);
	return (value);
}

void				pr_putstr_for_flag_u(t_printf *pr, char *buf)
{
	if (pr->flag_minus)
	{
		pr_putstr_repeat(pr, pr->precision, '0');
		pr_putstr_reverse(pr, buf);
		pr_putstr_repeat(pr, pr->width, ' ');
	}
	else
	{
		pr_putstr_repeat(pr, pr->width, ' ');
		pr_putstr_repeat(pr, pr->precision, '0');
		pr_putstr_reverse(pr, buf);
	}
}

void				pr_output_type_u(t_printf *pr)
{
	unsigned long long	value;
	char				buf[100];
	int					n;

	value = pr_read_value_type_u(pr);
	n = 0;
	while (value > 0)
	{
		buf[n] = '0' + value % 10;
		value = value / 10;
		n++;
	}
	if (n == 0 && pr->precision != 0)
	{
		buf[n] = '0';
		n++;
	}
	buf[n] = '\0';
	if (pr->flag_zero && pr->precision == -1 && !pr->flag_minus)
		pr->precision = pr->width;
	pr->precision -= n;
	pr->width -= n;
	if (pr->precision > 0)
		pr->width -= pr->precision;
	pr_putstr_for_flag_u(pr, buf);
}
