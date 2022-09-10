/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment_together.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 04:30:14 by ragirman          #+#    #+#             */
/*   Updated: 2022/07/02 04:30:19 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_together(t_swap *a, t_swap *b, int control)
{
	if (!control)
	{
		swap(a, 1);
		swap(b, 1);
		write(1, "ss\n", 3);
	}
}

void	rotate_together(t_swap *a, t_swap *b, int control)
{
	if (!control)
	{
		rotate(a, 1);
		rotate(b, 1);
		write(1, "rr\n", 3);
	}
}

void	rev_rotate_together(t_swap *a, t_swap *b, int control)
{
	if (!control)
	{
		rev_rotate(a, 1);
		rev_rotate(b, 1);
		write(1, "rrr\n", 4);
	}
}
