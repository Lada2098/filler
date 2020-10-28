/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:02:03 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:02:05 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	tmp = *alst;
	while (tmp)
	{
		*alst = (*alst)->next;
		del((tmp)->content, (tmp)->content_size);
		free(tmp);
		tmp = NULL;
		tmp = *alst;
	}
}
