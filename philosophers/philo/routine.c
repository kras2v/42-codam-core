/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:20:05 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/08 13:41:41 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_delay_even_philos(t_philo *philo)
{
	if (philo->number % 2 == 0)
	{
		usleep((philo->params.time_to_die / 2) * 1000);
	}
}

static int	ft_routine_process(t_philo *philo)
{
	if (ft_proceed_request_monitor(philo->number, TO_GETFORK) == FAIL)
		return (FAIL);
	if (ft_proceed_request_monitor(philo->number, TO_EAT) == FAIL)
		return (FAIL);
	if (ft_proceed_request_monitor(philo->number, TO_PUTFORK) == FAIL)
		return (FAIL);
	if (ft_proceed_request_monitor(philo->number, TO_CHECKMEAL) == FAIL)
		return (FAIL);
	if (ft_proceed_request_monitor(philo->number, TO_SLEEP) == FAIL)
		return (FAIL);
	if (ft_proceed_request_monitor(philo->number, TO_THINK) == FAIL)
		return (FAIL);
	return (OK);
}

static void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_monitor *monitor;

	philo = (t_philo *)arg;
	ft_get_monitor(&monitor);
	ft_proceed_request_monitor(philo->number, TO_START_DINNER);
	philo->last_meal = ft_get_current_time();
	ft_delay_even_philos(philo);
	while (TRUE)
	{
		if (ft_routine_process(philo) == FAIL)
			return (NULL);
	}
	return (NULL);
}

int	ft_create_threads(t_monitor *monitor)
{
	size_t	i;

	i = 0;
	ft_set_monitor(monitor);
	ft_proceed_request_monitor(0, 0);
	while (i < monitor->philos->params.number_of_philosophers)
	{
		if (pthread_create(&(monitor->philos + i)->thread, NULL,
				&ft_routine, (monitor->philos + i)) != 0)
			ft_puterror("Error creating thread");
		i++;
	}
	i = 0;
	pthread_mutex_lock(&(monitor->monitor_mutex));
	monitor->everyone_at_the_table = TRUE;
	pthread_mutex_unlock(&(monitor->monitor_mutex));
	while (i < monitor->philos->params.number_of_philosophers)
	{
		if (pthread_join((monitor->philos + i)->thread, NULL) != 0)
			ft_puterror("Error joining thread");
		i++;
	}
	return (OK);
}
