/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:37:59 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/08 10:56:18 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait_until_start_eating(t_monitor *saved_monitor)
{
	t_bool				everyone_at_the_table;

	while (TRUE)
	{
		pthread_mutex_lock(&(saved_monitor->monitor_mutex));
		everyone_at_the_table = saved_monitor->everyone_at_the_table;
		pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
		if (everyone_at_the_table == TRUE)
		{
			break ;
		}
		usleep(1000);
	}
	return ;
}

void	ft_eat(unsigned int philo_number, t_monitor *saved_monitor)
{
	if (ft_is_dinner_finished(philo_number, saved_monitor))
		return ;
	ft_print_state(philo_number, saved_monitor);
	pthread_mutex_lock(&(saved_monitor->monitor_mutex));
	saved_monitor->philos[philo_number - 1].meals++;
	saved_monitor->philos[philo_number - 1].last_meal = ft_get_current_time();
	pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
	usleep(1000 * saved_monitor->philos[philo_number - 1].params.time_to_eat);
	if (ft_is_dinner_finished(philo_number, saved_monitor))
		return ;
}

void	ft_psleep(unsigned int philo_number, t_monitor *saved_monitor)
{
	if (ft_is_dinner_finished(philo_number, saved_monitor))
		return ;
	ft_change_philo_state(philo_number, SLEEPING, saved_monitor);
	ft_print_state(philo_number, saved_monitor);
	usleep(1000 * saved_monitor->philos[philo_number - 1].params.time_to_sleep);
	if (ft_is_dinner_finished(philo_number, saved_monitor))
		return ;
}

void	ft_think(unsigned int philo_number, t_monitor *saved_monitor)
{
	t_state				state;

	if (ft_is_dinner_finished(philo_number, saved_monitor))
		return ;
	state = ft_get_current_philo_state(philo_number, saved_monitor);
	ft_change_philo_state(philo_number, THINKING, saved_monitor);
	ft_print_state(philo_number, saved_monitor);
	if (state == SLEEPING)
	{
		if (saved_monitor->philos[philo_number - 1].params.sleep_gap != 0)
			usleep(saved_monitor->philos[philo_number - 1].params.sleep_gap);
	}
	if (ft_is_dinner_finished(philo_number, saved_monitor))
		return ;
}
