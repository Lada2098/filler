/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:59:44 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 14:59:47 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int t;
	int a;

	i = 0;
	t = 1;
	a = 0;
	while (i < (length - 1))
	{
		while (tab[a] == tab[a + 1] && a < (length - 1))
			a++;
		if (f(tab[a], tab[a + 1]) > 0)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				t = 0;
		}
		else if (f(tab[a], tab[a + 1]) < 0)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				t = 0;
		}
		i++;
	}
	return (t);
}
