/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_output_type_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 22:46:54 by ayajirob          #+#    #+#             */
/*   Updated: 2020/08/16 00:17:33 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long
	pr_read_value_type_x(t_printf *pr)
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
	if (value == 0)
	{
		pr->flag_hash = 0;
	}
	if (pr->type == 'p')
	{
		pr->flag_hash = 1;
	}
	return (value);
}

void
	pr_define_final_width_and_precision_for_x(t_printf *pr, int n)
{
	if (pr->flag_hash)
		pr->width -= 2;
	if (pr->flag_zero && pr->precision == -1 && !pr->flag_minus)
		pr->precision = pr->width;
	pr->precision -= n;
	pr->width -= n;
	if (pr->precision > 0)
		pr->width -= pr->precision;
}

void
	pr_putstr_for_flag_x(t_printf *pr, char *buf)
{
	if (pr->flag_minus)
	{
		if (pr->flag_hash)
			pr_putstr(pr, pr->type == 'X' ? "0X" : "0x");
		pr_putstr_repeat(pr, pr->precision, '0');
		pr_putstr_reverse(pr, buf);
		pr_putstr_repeat(pr, pr->width, ' ');
	}
	else
	{
		pr_putstr_repeat(pr, pr->width, ' ');
		if (pr->flag_hash)
			pr_putstr(pr, pr->type == 'X' ? "0X" : "0x");
		pr_putstr_repeat(pr, pr->precision, '0');
		pr_putstr_reverse(pr, buf);
	}
}

void
	pr_output_type_x(t_printf *pr)
{
	unsigned long long	value;
	char				buf[100];
	int					n;

	if (pr->type == 'p')
		pr->length = LENGTH_LL;
	value = pr_read_value_type_x(pr);
	n = 0;
	while (value > 0)
	{
		if (pr->type == 'X')
			buf[n] = "0123456789ABCDEF"[value % 16];
		else
			buf[n] = "0123456789abcdef"[value % 16];
		value = value / 16;
		n++;
	}
	if (n == 0 && pr->precision != 0)
	{
		buf[n] = '0';
		n++;
	}
	buf[n] = '\0';
	pr_define_final_width_and_precision_for_x(pr, n);
	pr_putstr_for_flag_x(pr, buf);
}
