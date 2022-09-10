/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 04:31:22 by ragirman          #+#    #+#             */
/*   Updated: 2022/07/02 04:31:25 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoim(char *s, t_swap *a, t_swap *b)
{
	int		i;
	long	res;
	int		neg;

	i = 0;
	neg = 1;
	res = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			error_message(a, b);
		res = (res * 10) + s[i++] - '0';
		if ((res * neg) > __INT_MAX__ || (res * neg) < -__INT_MAX__ - 1)
			error_message(a, b);
	}
	return ((int)res * neg);
}
