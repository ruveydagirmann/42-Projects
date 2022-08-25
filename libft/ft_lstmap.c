/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:47:25 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:34:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;
	t_list	*new;

	if (!lst)
		return (0);
	list = ft_lstnew(f(lst->content));
	if (!list)
		return (0);
	temp = list;
	new = lst->next;
	while (new)
	{
		temp->next = ft_lstnew((*f)(new->content));
		if (!temp)
		{
			ft_lstclear(&list, del);
			return (0);
		}
		temp = temp->next;
		new = new->next;
	}
	return (list);
}
