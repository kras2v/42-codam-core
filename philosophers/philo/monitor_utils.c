/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:32:35 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/07 13:05:43 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_monitor	*ft_save_monitor(t_monitor *monitor)
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
		(*saved_monitor) = ft_save_monitor(NULL);
		return (1);
	}
	return (0);
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
