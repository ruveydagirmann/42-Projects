/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:47:37 by ragirman          #+#    #+#             */
/*   Updated: 2022/08/25 12:34:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*t;
	int		i;

	t = lst;
	i = 0;
	while (t != NULL)
	{
		t = t -> next;
		i++;
	}
	return (i);
}