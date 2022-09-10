/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 04:33:39 by ragirman          #+#    #+#             */
/*   Updated: 2022/07/02 04:33:41 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode;

	lastnode = ft_lstlast(*lst);
	if (!lastnode)
		*lst = new;
	else
		lastnode->next = new;
}
/*#include <stdio.h>
int main(void)
{
	t_list *a,*b,*c;
	a=malloc(sizeof(t_list));
	b=malloc(sizeof(t_list));
	c=malloc(sizeof(t_list));
	a->content="ilknur";
	a->next=b;
	b->content="yarikan";
	c->content="Ahil";
	c->next=NULL;
	ft_lstadd_back(&a,c);
	printf("%s\n",(char*)(ft_lstlast(a))->content);
}*/
