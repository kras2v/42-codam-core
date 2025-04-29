/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:06:30 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/28 22:31:40 by valeriia         ###   ########.fr       */
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

typedef enum e_state
{
	DIE,
	EAT,
	SLEEP,
	THINK
} t_state;

typedef struct s_fork
{
	unsigned int	number;
	bool			locked;
} t_fork;

typedef struct s_philo_params
{
	unsigned int	number_of_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	long			number_of_times_each_philosopher_must_eat;
}	t_philo_params;

typedef struct s_philo
{
	t_philo_params	params;
	unsigned int	number;
	long			last_meal;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	t_fork			*forks;
	pthread_mutex_t	*forks_mutex;
	pthread_t		thread;
	bool			*everyone_at_the_table;
	pthread_mutex_t	*print_state_mutex;
	t_state			state;
}	t_philo;

typedef struct s_philo_routine
{
	t_fork			*forks;
	pthread_mutex_t	*forks_mutex;
	t_philo			*philos;
	pthread_mutex_t	portions_eaten_mutex;
	pthread_mutex_t	print_state_mutex;
	unsigned int	portions_eaten;
	bool			everyone_at_the_table;
}	t_philo_routine;

long	ft_validate_number_input(char *string);

void	ft_cleanup_routine(t_philo_routine *routine);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_calculate_num_len(int number);
bool	ft_isanum(char character);
void	ft_puterror(char *msg);
int		ft_strlen(char *str);
long	ft_atol(char *str);

void	ft_print_info_message(void);
void	ft_print_philo_params(t_philo_params philo_params);

#endif
