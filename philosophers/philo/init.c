/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:40:11 by ragirman          #+#    #+#             */
/*   Updated: 2022/09/09 12:43:15 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	init_arg(t_arg *av, int ac, char **argv)
{
	av->nb_philo = ft_atoi(argv[1]);
	av->time_to_die = ft_atoi(argv[2]);
	av->time_to_eat = ft_atoi(argv[3]);
	av->time_to_sleep = ft_atoi(argv[4]);
	av->is_died = false;
	if (ac == 6)
		av->must_eat = ft_atoi(argv[5]);
	else
		av->must_eat = -1;
	if (pthread_mutex_init(&(av->time_mutex), NULL))
		return (1);
	if (pthread_mutex_init(&(av->died_lock), NULL))
		return (1);
	if (pthread_mutex_init(&(av->print_lock), NULL))
		return (1);
	return (0);
}

int	init_philo(t_arg *av)
{
	int	i;

	i = 0;
	while (i < av->nb_philo)
	{
		av->philo[i].start_time = get_time();
		av->philo[i].id = i + 1;
		av->philo[i].arg = av;
		av->philo[i].ate_count = 0;
		if (i == 0)
			av->philo[i].prev_fork = &(av->philo[av->nb_philo - 1].fork);
		else
			av->philo[i].prev_fork = &(av->philo[i - 1].fork);
		if (pthread_mutex_init(&(av->philo[i].fork), NULL))
			return (1);
		i++;
	}
	return (0);
}
