/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:32:35 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/08 13:32:48 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_monitor	*ft_set_monitor(t_monitor *monitor)
{
	static t_monitor	*saved_monitor;

	if (monitor == NULL)
	{
		return (saved_monitor);
	}
	if (saved_monitor == NULL)
	{
		saved_monitor = monitor;
	}
	return (saved_monitor);
}

int	ft_get_monitor(t_monitor **saved_monitor)
{
	if (saved_monitor && (*saved_monitor) == NULL)
	{
		(*saved_monitor) = ft_set_monitor(NULL);
		return (1);
	}
	return (0);
}

static int	ft_is_state_finish(
	unsigned int philo_number, t_monitor *saved_monitor)
{
	t_state	state;

	state = ft_get_current_philo_state(philo_number, saved_monitor);
	if (state == FINISH || state == FULL)
		return (TRUE);
	return (FALSE);
}

int	ft_proceed_request_monitor(unsigned int philo_number, t_request request)
{
	static t_monitor	*saved_monitor;

	if (saved_monitor == NULL)
		return (ft_get_monitor(&saved_monitor), OK);
	if (request == TO_START_DINNER)
	{
		ft_wait_until_start_eating(saved_monitor);
		ft_print_state(philo_number, saved_monitor);
		return (OK);
	}
	else if (request == TO_GETFORK)
		ft_take_fork(philo_number, saved_monitor);
	else if (request == TO_EAT)
		ft_eat(philo_number, saved_monitor);
	else if (request == TO_PUTFORK)
		ft_put_forks(philo_number, saved_monitor);
	else if (request == TO_CHECKMEAL)
		ft_check_meal(philo_number, saved_monitor);
	else if (request == TO_SLEEP)
		ft_psleep(philo_number, saved_monitor);
	else if (request == TO_THINK)
		ft_think(philo_number, saved_monitor);
	if (ft_is_state_finish(philo_number, saved_monitor))
		return (FAIL);
	return (OK);
}

t_monitor	*ft_assign_monitor(t_philo *philos)
{
	t_monitor	*monitor;

	monitor = ft_calloc(1, sizeof(t_monitor));
	if (monitor == NULL)
		return (NULL);
	monitor->philos = philos;
	pthread_mutex_init(&monitor->print_state_mutex, NULL);
	pthread_mutex_init(&monitor->monitor_mutex, NULL);
	monitor->forks
		= ft_calloc(philos->params.number_of_philosophers, sizeof(t_fork));
	if (monitor->forks == NULL)
	{
		pthread_mutex_destroy(&monitor->print_state_mutex);
		pthread_mutex_destroy(&monitor->monitor_mutex);
		free(monitor);
		return (NULL);
	}
	if (ft_init_forks(philos, monitor) == FAIL)
	{
		pthread_mutex_destroy(&monitor->print_state_mutex);
		pthread_mutex_destroy(&monitor->monitor_mutex);
		free(monitor);
		return (NULL);
	}
	return (monitor);
}
