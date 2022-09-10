/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 04:35:13 by ragirman          #+#    #+#             */
/*   Updated: 2022/07/02 04:40:57 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	sayac;

	if (!lst)
		return (0);
	sayac = 0;
	while (lst)
	{
		sayac++;
		lst = lst->next;
	}
	return (sayac);
}
