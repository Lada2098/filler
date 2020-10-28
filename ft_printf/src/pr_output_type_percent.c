/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_output_type_percent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:54:49 by ayajirob          #+#    #+#             */
/*   Updated: 2020/08/15 18:19:51 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_output_type_percent(t_printf *pr)
{
	int		n;

	n = pr->width - 1;
	if (pr->flag_minus)
	{
		pr_putchar(pr, '%');
		pr_putstr_repeat(pr, n, ' ');
	}
	else
	{
		pr_putstr_repeat(pr, n, ' ');
		pr_putchar(pr, '%');
	}
}
