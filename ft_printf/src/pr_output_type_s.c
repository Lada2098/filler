/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_output_type_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 22:16:19 by ayajirob          #+#    #+#             */
/*   Updated: 2020/08/15 18:17:30 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_output_type_s(t_printf *pr)
{
	int		n;
	char	*value;

	value = (char *)va_arg(pr->ap, char *);
	if (value == NULL)
		value = "(null)";
	n = ft_strlen(value);
	if (pr->precision == -1 || pr->precision > n)
		pr->precision = n;
	pr->width -= pr->precision;
	if (pr->flag_minus)
	{
		pr_putstr_precision(pr, value, pr->precision);
		pr_putstr_repeat(pr, pr->width, ' ');
	}
	else
	{
		pr_putstr_repeat(pr, pr->width, ' ');
		pr_putstr_precision(pr, value, pr->precision);
	}
}
