/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 21:29:48 by ayajirob          #+#    #+#             */
/*   Updated: 2020/08/15 18:25:31 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	pr;

	ft_bzero(&pr, sizeof(t_printf));
	pr.format = format;
	va_start(pr.ap, format);
	pr_while(&pr);
	va_end(pr.ap);
	return (pr.result);
}
