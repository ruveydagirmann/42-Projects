/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:22:54 by ragirman          #+#    #+#             */
/*   Updated: 2022/09/09 13:20:36 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	destroy_mutex(t_arg *arg)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&(arg->died_lock)))
		return (1);
	if (pthread_mutex_destroy(&(arg->print_lock)))
		return (1);
	if (pthread_mutex_destroy(&(arg->time_mutex)))
		return (1);
	while (i < arg->nb_philo)
	{
		if (pthread_mutex_destroy(&(arg->philo[i].fork)))
			return (1);
		i++;
	}
	return (0);
}

static int	create_thread(t_arg *av, pthread_t *judge)
{
	int	i;

	i = 0;
	while (i < av->nb_philo)
	{
		av->philo[i].last_eat_time = get_time();
		if (pthread_create(&(av->philo[i].th), NULL, \
		create_philo, &(av->philo[i])))
			return (1);
			i++;
	}
	if (pthread_create(judge, NULL, control_philo_life, av))
		return (0);
	return (0);
}

static int	join_thread(t_arg *av, pthread_t *judge)
{
	int	i;

	i = 0;
	while (i < av->nb_philo)
	{
		if (pthread_join(av->philo[i].th, NULL))
			return (1);
		i++;
	}
	if (pthread_join(*judge, NULL))
		return (1);
	return (0);
}

int	main(int ac, char **argv)
{
	t_arg				arg;
	pthread_t			judge;

	if (ac == 5 || ac == 6)
	{
		if (arg_control(argv) || init_arg(&arg, ac, argv) \
			|| control_value(&arg) == 1)
			return (1);
		if (control_value(&arg) == 2)
		{
			printf("0	1 has taken a fork.\n");
			usleep(arg.time_to_die * 1000);
			printf("%llu	1 is died. \n", arg.time_to_die);
			return (1);
		}
		if (init_philo(&arg))
			return (1);
		if (create_thread(&arg, &judge) || join_thread(&arg, &judge))
			return (1);
		if (destroy_mutex(&arg))
			return (1);
	}
	return (0);
}
