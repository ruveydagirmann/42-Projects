/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge_verb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:40:42 by ragirman          #+#    #+#             */
/*   Updated: 2022/09/08 17:40:03 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	control_philo_life_tools(t_philo *philo, t_arg *arg)
{
	static bool	printable = true;

	pthread_mutex_lock(&(arg->time_mutex));
	if (get_time() - philo->last_eat_time >= arg->time_to_die)
	{
		pthread_mutex_unlock(&(arg->time_mutex));
		pthread_mutex_lock(&(arg->died_lock));
		arg->is_died = true;
		pthread_mutex_unlock(&(arg->died_lock));
		if (printable)
		{
			printf("%llums	%d	%s\n", get_time() - philo->start_time, \
			philo->id, DIED);
			printable = false;
			return ;
		}
	}
	else
		pthread_mutex_unlock(&(arg->time_mutex));
}

void	*control_philo_life(void *v_arg)
{
	int			i;
	t_arg		*arg;

	arg = (t_arg *)v_arg;
	i = 1;
	while (!(arg->is_died))
	{
		if (i == arg->nb_philo)
			i = 0;
		control_philo_life_tools(&(arg->philo[i]), arg);
		pthread_mutex_lock(&(arg->died_lock));
		if (arg->must_eat != -1 && \
			(arg->philo[i].ate_count == arg->must_eat))
		{
			pthread_mutex_unlock(&(arg->died_lock));
			break ;
		}
		pthread_mutex_unlock(&(arg->died_lock));
		i++;
	}
	return (NULL);
}
