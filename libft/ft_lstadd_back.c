/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:46:45 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:33:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{	
	t_list	*t;

	t = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{	
		t = ft_lstlast(*lst);
		t -> next = new;
	}
}
