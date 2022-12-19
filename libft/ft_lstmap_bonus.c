/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:27:49 by ffeaugas          #+#    #+#             */
/*   Updated: 2022/10/07 14:22:03 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst_begin;
	t_list	*newlst;

	if (!lst || !f || !del)
		return (NULL);
	newlst_begin = ft_lstnew(f(lst->content));
	newlst = newlst_begin;
	while (lst->next)
	{
		lst = lst->next;
		newlst->next = ft_lstnew(f(lst->content));
		if (!newlst)
		{
			ft_lstclear(&newlst_begin, del);
			return (NULL);
		}
		newlst = newlst->next;
	}
	return (newlst_begin);
}
