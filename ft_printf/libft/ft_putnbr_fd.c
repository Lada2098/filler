/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:07:23 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:07:26 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	m;
	long	nb;

	nb = n;
	m = 1;
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar_fd('-', fd);
	}
	while (nb / (m * 10) > 0)
		m = m * 10;
	while (m > 0)
	{
		ft_putchar_fd((nb / m + '0'), fd);
		nb = nb % m;
		m = m / 10;
	}
}
