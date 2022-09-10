/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 04:34:49 by ragirman          #+#    #+#             */
/*   Updated: 2022/07/02 04:42:32 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*pos;

	pos = NULL;
	while (lst)
	{
		temp = ft_lstnew((f(lst->content)));
		if (!temp)
		{
			ft_lstclear(&pos, del);
			return (NULL);
		}
		ft_lstadd_back(&pos, temp);
		lst = lst->next;
	}
	temp->next = NULL;
	return (pos);
}
