/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:32:15 by ragirman          #+#    #+#             */
/*   Updated: 2022/09/09 13:00:28 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	print_status(t_philo *philo, unsigned long long time, char *msg)
{
	pthread_mutex_lock(&(philo->arg->print_lock));
	pthread_mutex_lock(&(philo->arg->died_lock));
	if (!philo->arg->is_died)
		printf("%llums	%d	%s\n", get_time() - time, philo->id, msg);
	pthread_mutex_unlock(&(philo->arg->print_lock));
	pthread_mutex_unlock(&(philo->arg->died_lock));
}

static	void	sleeping_philo(t_philo *philo, int i)
{
	unsigned long long	start_time;

	if (i == 1)
	{
		while (get_time() - philo->last_eat_time <= philo->arg->time_to_eat)
			usleep(100);
	}
	else
	{
		start_time = get_time();
		while (get_time() - start_time <= philo->arg->time_to_sleep)
			usleep(100);
	}
}

static	void	eating_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->prev_fork);
	print_status(philo, philo->start_time, TAKEN);
	pthread_mutex_lock(&(philo->fork));
	print_status(philo, philo->start_time, TAKEN);
	print_status(philo, philo->start_time, EATING);
	pthread_mutex_lock(&(philo->arg->time_mutex));
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&(philo->arg->time_mutex));
	sleeping_philo(philo, 1);
	pthread_mutex_lock(&(philo->arg->died_lock));
	(philo->ate_count)++;
	pthread_mutex_unlock(&(philo->arg->died_lock));
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(philo->prev_fork);
}

void	*create_philo(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	philo->start_time = get_time();
	if (!(philo->id % 2))
		usleep(1000);
	while (1)
	{
		eating_philo(philo);
		print_status(philo, philo->start_time, SLEEPING);
		sleeping_philo(philo, 0);
		print_status(philo, philo->start_time, THINKING);
		pthread_mutex_lock(&(philo->arg->died_lock));
		if (philo->arg->is_died || (philo->arg->must_eat != -1 && \
			philo->ate_count == philo->arg->must_eat))
		{
			pthread_mutex_unlock(&(philo->arg->died_lock));
			break ;
		}
		pthread_mutex_unlock(&(philo->arg->died_lock));
	}
	return (NULL);
}
