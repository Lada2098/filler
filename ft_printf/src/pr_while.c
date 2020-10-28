/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_while.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:48:32 by gekans            #+#    #+#             */
/*   Updated: 2020/08/16 02:48:35 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_while(t_printf *pr)
{
	if (ft_strequ(pr->format, "%"))
		return ;
	while (*pr->format)
	{
		if (*pr->format == '%')
		{
			pr_read_specific(pr);
			pr_output(pr);
		}
		else
		{
			pr_putchar(pr, *pr->format);
			pr->format++;
		}
	}
}
