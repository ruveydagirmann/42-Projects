/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:39:48 by ragirman          #+#    #+#             */
/*   Updated: 2022/09/08 16:19:05 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	ft_atoi(const char *str)
{
	int	sum;
	int	found;

	sum = 0;
	found = 1;
	while (*str == ' ' || *str == '\t' || \
			*str == '\n' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+')
		str++;
	while (*str && found)
	{
		if (*str >= '0' && *str <= '9')
			sum = sum * 10 + *str - '0';
		else
			found = 0;
		str++;
	}
	return (sum);
}
