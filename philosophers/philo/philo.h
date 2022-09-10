/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:54:23 by ragirman          #+#    #+#             */
/*   Updated: 2022/09/09 12:50:10 by ragirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

# define TAKEN " has taken a fork."
# define EATING " is eating."
# define SLEEPING " is sleeping."
# define THINKING " is thinking."
# define DIED " is died."

typedef struct s_philo
{
	int					id;
	pthread_t			th;
	int					ate_count;
	pthread_mutex_t		fork;
	pthread_mutex_t		*prev_fork;
	unsigned long long	start_time;
	unsigned long long	last_eat_time;
	struct s_arg		*arg;
}	t_philo;

typedef struct s_arg
{
	int					nb_philo;
	int					must_eat;
	bool				is_died;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	pthread_mutex_t		time_mutex;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		died_lock;
	t_philo				philo[200];

}	t_arg;

int					arg_control(char **av);
int					control_value(t_arg *av);
int					init_arg(t_arg *arg, int ac, char **av);
int					init_philo(t_arg *av);
int					ft_atoi(const char *str);
void				*create_philo(void *philo);
void				*control_philo_life(void *_arg);
unsigned long long	get_time(void);

#endif
