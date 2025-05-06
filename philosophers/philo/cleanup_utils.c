/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:46:53 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/06 20:48:11 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_cleanup_philos(t_philo *philos)
{
	if (philos != NULL)
	{
		free(philos);
	}
}

void	ft_cleanup_forks(t_monitor *monitor, size_t	number_of_philosophers)
{
	size_t	i;

	i = 0;
	if (monitor->forks != NULL)
	{
		while (i < number_of_philosophers)
		{
			pthread_mutex_destroy(&((monitor->forks + i)->mutex));
			i++;
		}
	}
	if (monitor->forks != NULL)
	{
		free(monitor->forks);
	}
}

void	ft_cleanup_monitor(t_monitor *monitor)
{
	ft_cleanup_forks(monitor, monitor->philos->params.number_of_philosophers);
	ft_cleanup_philos(monitor->philos);
	pthread_mutex_destroy(&monitor->print_state_mutex);
	pthread_mutex_destroy(&monitor->monitor_mutex);
	free(monitor);
}
