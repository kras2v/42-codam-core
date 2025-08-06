/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:40:56 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/08 13:30:33 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_state	ft_get_current_philo_state(
	unsigned int philo_number, t_monitor *saved_monitor)
{
	t_state				state;

	pthread_mutex_lock(&(saved_monitor->monitor_mutex));
	state = saved_monitor->philos[philo_number - 1].state;
	pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
	return (state);
}

static void	ft_check_death(unsigned int philo_number, t_monitor *saved_monitor)
{
	size_t	i;

	if (saved_monitor->philos[philo_number - 1].params.time_to_die
		<= ft_get_current_time()
		- saved_monitor->philos[philo_number - 1].last_meal)
	{
		pthread_mutex_lock(&(saved_monitor->monitor_mutex));
		saved_monitor->philos[philo_number - 1].state = DIED;
		saved_monitor->is_someone_dead = TRUE;
		pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
		ft_print_state(
			saved_monitor->philos[philo_number - 1].number, saved_monitor);
		pthread_mutex_lock(&(saved_monitor->monitor_mutex));
		i = 0;
		while (i < saved_monitor->philos[philo_number - 1]
			.params.number_of_philosophers)
		{
			(saved_monitor->philos[i]).state = FINISH;
			i++;
		}
		pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
	}
}

int	ft_is_dinner_finished(unsigned int philo_number, t_monitor *saved_monitor)
{
	t_state	state;

	ft_check_death(philo_number, saved_monitor);
	state = ft_get_current_philo_state(philo_number, saved_monitor);
	if (state == FINISH)
		return (TRUE);
	return (FALSE);
}

void	ft_change_fork_state(t_fork *fork, t_bool locked)
{
	pthread_mutex_lock(&(fork->mutex));
	fork->locked = locked;
	pthread_mutex_unlock(&(fork->mutex));
}

void	ft_change_philo_state(
	unsigned int philo_number, t_state state, t_monitor *saved_monitor)
{
	pthread_mutex_lock(&(saved_monitor->monitor_mutex));
	saved_monitor->philos[philo_number - 1].state = state;
	pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
}
