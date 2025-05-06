/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:06:30 by kvalerii          #+#    #+#             */
/*   Updated: 2025/05/06 20:48:31 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#	include <stdio.h>
#	include <stdlib.h>
#	include <limits.h>
#	include <pthread.h>
#	include <unistd.h>
#	include <sys/time.h>

//!REMOVE
#	include <stdbool.h>
#	include "colors.h"
#	include <string.h>

#	define OK 0
#	define FAIL 1
#	define NOTSET -42

typedef enum	e_state
{
	EATING,
	SLEEPING,
	THINKING,
	HUNGRY,
	GOTFORK,
	PUTFORK,
	FINISH,
	DIED,
	FULL,
} t_state;

typedef enum	e_pthread_kind
{
	WAITER,
	PHILOSOPHER
}	t_pthread_kind;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	unsigned int	number;
	bool			locked;
} t_fork;

typedef struct s_philo_params
{
	unsigned int	number_of_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	long			sleep_gap;
	long			ask_fork_retry;
	long			number_of_times_each_philosopher_must_eat;
}	t_philo_params;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	number;
	t_state			state;
	t_philo_params	params;
	long			last_meal;
	t_fork			*left_fork;
	t_fork			*right_fork;
	unsigned int	meals;
}	t_philo;

typedef struct s_request
{
	t_philo			*philo;
} t_request;

typedef struct s_monitor
{
	t_fork			*forks;
	t_philo			*philos;
	// long			start_time;
	bool			is_someone_dead;
	bool			everyone_at_the_table;
	pthread_mutex_t	monitor_mutex;
	pthread_mutex_t	print_state_mutex;
}	t_monitor;

long	ft_validate_number_input(char *string);

void	ft_cleanup_forks(t_monitor *routine, size_t	number_of_philosophers);
void	ft_cleanup_monitor(t_monitor *monitor);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_calculate_num_len(int number);
bool	ft_isanum(char character);
void	ft_puterror(char *msg);
int		ft_strlen(char *str);
long	ft_atol(char *str);

void	ft_print_info_message(void);
void	ft_print_philo_params(t_philo_params philo_params);


//CLEANUP UTILS
void	ft_cleanup_philos(t_philo *philos);
void	ft_cleanup_forks(t_monitor *monitor, size_t	number_of_philosophers);
void	ft_cleanup_monitor(t_monitor *monitor);

#endif
