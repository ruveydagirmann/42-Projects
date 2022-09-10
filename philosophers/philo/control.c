/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:24:39 by ragirman          #+#    #+#             */
/*   Updated: 2022/09/08 16:22:11 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	arg_control(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][0] == '+' && \
			!(av[i][j + 1] <= '9' && av[i][j + 1] >= '0'))
				return (1);
			if (!(av[i][j] <= '9' && av[i][j] >= '0') && av[i][0] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	control_value(t_arg *av)
{
	if (av->nb_philo == 1)
		return (2);
	if (av->nb_philo > 200 || av->nb_philo < 2)
		return (1);
	if (av->time_to_die == 0)
		return (1);
	if (av->must_eat == 0)
		return (1);
	return (0);
}
