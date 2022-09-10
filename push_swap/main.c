/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 04:29:42 by ragirman          #+#    #+#             */
/*   Updated: 2022/07/02 04:44:33 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	a;
	t_swap	b;

	a.stack = 'a';
	b.stack = 'b';
	if (argc >= 2 && argc <= 1000)
		more_args(argc, argv, &a, &b);
	else
		return (0);
	check_double(&a, &b);
	check_list(&a, &b);
	indexing(&a);
	if (a.size > 5)
		sort_list(&a, &b);
	else
		smaller_list(&a, &b);
	free(a.array);
	free(b.array);
	return (0);
}
