/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:06:30 by kvalerii          #+#    #+#             */
/*   Updated: 2025/05/08 13:32:48 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include "colors.h"
# include "ft_boolean.h"

# define OK 0
# define FAIL 1
# define NOTSET -42

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	HUNGRY,
	GOTFORK,
	FINISH,
	DIED,
	FULL,
}	t_state;

typedef enum e_request
{
	TO_EAT,
	TO_SLEEP,
	TO_THINK,
	TO_GETFORK,
	TO_PUTFORK,
	TO_CHECKMEAL,
	TO_START_DINNER,
}	t_request;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	unsigned int	number;
	t_bool			locked;
}	t_fork;

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

typedef struct s_monitor
{
	t_fork			*forks;
	t_philo			*philos;
	t_bool			is_someone_dead;
	t_bool			everyone_at_the_table;
	pthread_mutex_t	monitor_mutex;
	pthread_mutex_t	print_state_mutex;
}	t_monitor;

//UTILS
long		ft_validate_number_input(char *string);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_calculate_num_len(int number);
t_bool		ft_isanum(char character);
void		ft_puterror(char *msg);
int			ft_strlen(char *str);
long		ft_atol(char *str);
long		ft_get_current_time(void);

//PRINT
void		ft_print_info_message(void);
void		ft_print_state(unsigned int philo_number, t_monitor *monitor);

//ROUTINE
int			ft_create_threads(t_monitor *monitor);
void		ft_wait_until_start_eating(t_monitor *monitor);
void		ft_eat(unsigned int philo_number, t_monitor *monitor);
void		ft_psleep(unsigned int philo_number, t_monitor *monitor);
void		ft_think(unsigned int philo_number, t_monitor *monitor);

//FORKS
t_bool		ft_is_fork_released(t_fork *fork);
void		ft_put_forks(unsigned int philo_number, t_monitor *monitor);
void		ft_take_fork(unsigned int philo_number, t_monitor *monitor);
int			ft_init_forks(t_philo *philos, t_monitor *monitor);
void		ft_change_fork_state(t_fork *fork, t_bool locked);

//PHILO
int			ft_assign_philo_params(char **argv, t_philo_params *philo_params);
t_philo		*ft_assign_philos(t_philo_params philo_params);
t_state		ft_get_current_philo_state(
				unsigned int philo_number, t_monitor *monitor);
void		ft_change_philo_state(
				unsigned int philo_number, t_state state, t_monitor *monitor);

//MONITOR
t_monitor	*ft_set_monitor(t_monitor *monitor);
t_monitor	*ft_assign_monitor(t_philo *philos);
int			ft_get_monitor(t_monitor **saved_monitor);
int			ft_proceed_request_monitor(
				unsigned int philo_number, t_request request);

//CHECKER
int			ft_is_dinner_finished(
				unsigned int philo_number, t_monitor *monitor);
void		ft_check_meal(unsigned int philo_number, t_monitor *monitor);
void		ft_check_if_available(
				unsigned int philo_number, t_monitor *monitor);

//CLEANUP
void		ft_cleanup_philos(t_philo *philos);
void		ft_cleanup_forks(t_monitor *monitor, size_t	number_of_philosophers);
void		ft_cleanup_monitor(t_monitor *monitor);

#endif
