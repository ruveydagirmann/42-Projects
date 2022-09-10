/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 04:31:05 by ragirman          #+#    #+#             */
/*   Updated: 2022/07/02 04:31:08 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_func(t_swap *a, t_swap *b)
{
	free(a->array);
	free(b->array);
	exit(1);
}

void	error_message(t_swap *a, t_swap *b)
{
	write(2, "Error\n", 6);
	free_func(a, b);
}
