/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_output_type_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 03:54:14 by ayajirob          #+#    #+#             */
/*   Updated: 2020/08/16 00:37:26 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double long
	pr_define_first_sign_and_length_type_f(t_printf *pr)
{
	double long		value;

	if (pr->length == LENGTH_BIGL)
		value = (double long)va_arg(pr->ap, double long);
	else
		value = (double long)va_arg(pr->ap, double);
	pr->first_sign = '\0';
	if (pr->flag_space)
		pr->first_sign = ' ';
	if (pr->flag_plus)
		pr->first_sign = '+';
	if (value < 0)
	{
		pr->first_sign = '-';
		value = -value;
	}
	if (pr->precision == -1)
		pr->precision = 6;
	return (value);
}

int
	pr_fill_buf_for_type_f_part2(t_printf *pr, char *buf,
	unsigned long long integer_part, unsigned long long fractional_part)
{
	int	n;

	n = 0;
	while (fractional_part > 0)
	{
		buf[n] = '0' + fractional_part % 10;
		fractional_part = fractional_part / 10;
		n++;
	}
	while (n < pr->precision)
		buf[n++] = '0';
	if (n > 0)
		buf[n++] = '.';
	if (integer_part == 0)
		buf[n++] = '0';
	while (integer_part > 0)
	{
		buf[n] = '0' + integer_part % 10;
		integer_part = integer_part / 10;
		n++;
	}
	buf[n] = '\0';
	return (n);
}

int
	pr_fill_buf_for_type_f(t_printf *pr, char *buf, double long value)
{
	unsigned long long		integer_part;
	unsigned long long		fractional_part;
	unsigned long long		pow10;
	int						n;

	pow10 = pr_pow10(pr->precision + 1);
	integer_part = (unsigned long long)value;
	value = (value - (double long)integer_part) * (double long)pow10;
	if ((unsigned long long)value % 10 > 4)
		value = value / 10 + 1;
	else
		value = value / 10;
	integer_part += (unsigned long long)value / (pow10 / 10);
	fractional_part = (unsigned long long)value % (pow10 / 10);
	n = pr_fill_buf_for_type_f_part2(pr, buf, integer_part, fractional_part);
	return (n);
}

void
	pr_putstr_for_flag_f(t_printf *pr, char *buf, char sign)
{
	if (pr->flag_minus)
	{
		if (sign)
			pr_putchar(pr, sign);
		pr_putstr_repeat(pr, pr->precision, '0');
		pr_putstr_reverse(pr, buf);
		pr_putstr_repeat(pr, pr->width, ' ');
	}
	else
	{
		pr_putstr_repeat(pr, pr->width, ' ');
		if (sign)
			pr_putchar(pr, sign);
		pr_putstr_repeat(pr, pr->precision, '0');
		pr_putstr_reverse(pr, buf);
	}
}

void
	pr_output_type_f(t_printf *pr)
{
	double long				value;
	char					buf[100];
	int						n;

	value = pr_define_first_sign_and_length_type_f(pr);
	n = pr_fill_buf_for_type_f(pr, buf, value);
	if (pr->first_sign)
		pr->width -= 1;
	if (pr->flag_zero && !pr->flag_minus)
		pr->precision = pr->width;
	pr->precision -= n;
	pr->width -= n;
	if (pr->precision > 0)
		pr->width -= pr->precision;
	pr_putstr_for_flag_f(pr, buf, pr->first_sign);
}
