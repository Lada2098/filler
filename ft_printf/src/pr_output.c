/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:48:55 by gekans            #+#    #+#             */
/*   Updated: 2020/08/16 02:48:59 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_output(t_printf *pr)
{
	if (pr->type == 'd')
		pr_output_type_d(pr);
	else if (pr->type == 'i')
		pr_output_type_d(pr);
	else if (pr->type == 'p')
		pr_output_type_x(pr);
	else if (pr->type == 'o')
		pr_output_type_o(pr);
	else if (pr->type == 'u')
		pr_output_type_u(pr);
	else if (pr->type == 'c')
		pr_output_type_с(pr);
	else if (pr->type == 's')
		pr_output_type_s(pr);
	else if (pr->type == 'x')
		pr_output_type_x(pr);
	else if (pr->type == 'X')
		pr_output_type_x(pr);
	else if (pr->type == 'f')
		pr_output_type_f(pr);
	else if (pr->type == '%')
		pr_output_type_percent(pr);
}
