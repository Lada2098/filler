/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putstr_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:26:46 by ayajirob          #+#    #+#             */
/*   Updated: 2020/08/15 18:20:24 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_putstr_reverse(t_printf *pr, char *buf)
{
	int	n;

	n = ft_strlen(buf);
	while (n > 0)
	{
		n--;
		pr_putchar(pr, buf[n]);
	}
}
