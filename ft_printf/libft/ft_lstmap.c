/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:03:01 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 15:03:04 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*rez;
	t_list	*rr;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(rez = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	rez = f(lst);
	rr = rez;
	lst = lst->next;
	while (lst)
	{
		if (!(rez->next = f(lst)))
		{
			free(rez->content);
			free(rez->next);
			return (NULL);
		}
		rez = rez->next;
		lst = lst->next;
	}
	return (rr);
}
