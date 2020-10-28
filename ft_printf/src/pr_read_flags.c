/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_read_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:14:26 by ayajirob          #+#    #+#             */
/*   Updated: 2020/08/15 18:09:25 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_read_flags_hash_zero(t_printf *pr)
{
	if (*pr->format == '0')
	{
		pr->flag_zero = 1;
		pr->format++;
	}
	else if (*pr->format == '#')
	{
		pr->flag_hash = 1;
		pr->format++;
	}
	else
		return ;
}

void	pr_read_flags(t_printf *pr)
{
	while (*pr->format)
	{
		if (*pr->format == '-')
		{
			pr->flag_minus = 1;
			pr->format++;
		}
		else if (*pr->format == '+')
		{
			pr->flag_plus = 1;
			pr->format++;
		}
		else if (*pr->format == ' ')
		{
			pr->flag_space = 1;
			pr->format++;
		}
		else if (*pr->format == '0' || *pr->format == '#')
			pr_read_flags_hash_zero(pr);
		else
			return ;
	}
}
