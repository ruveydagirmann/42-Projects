/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 04:30:35 by ragirman          #+#    #+#             */
/*   Updated: 2022/07/02 04:30:37 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_swap *data, int control)
{
	int	tmp;

	if (data->size < 2)
		write(1, "no number to swap", 18);
	tmp = data->array[data->size - 1];
	data->array[data->size - 1] = data->array[data->size - 2];
	data->array[data->size - 2] = tmp;
	if (!control)
	{
		if (data->stack == 'a')
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}

void	rotate(t_swap *data, int control)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = data->array[data->size - 1];
	while (++i < data->size - 1)
		data->array[data->size - 1 - i] = data->array[data->size - 2 - i];
	data->array[0] = tmp;
	if (!control)
	{
		if (data->stack == 'a')
			write(1, "ra\n", 3);
		else if (data->stack == 'b')
			write(1, "rb\n", 3);
	}
}

void	push(t_swap *data, t_swap *data1, int control)
{
	if (data->size < 1)
		write(1, "no number to push", 18);
	data1->array[data1->size] = data->array[data->size - 1];
	data1->size += 1;
	data->size -= 1;
	if (!control)
	{
		if (data->stack == 'a')
			write(1, "pb\n", 3);
		else
			write(1, "pa\n", 3);
	}
}

void	rev_rotate(t_swap *data, int control)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = data->array[0];
	while (++i < data->size - 1)
		data->array[i] = data->array[i + 1];
	data->array[data->size - 1] = tmp;
	if (!control)
	{
		if (data->stack == 'a')
			write(1, "rra\n", 4);
		else if (data->stack == 'b')
			write(1, "rrb\n", 4);
	}
}
