/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:39:50 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/07 13:01:31 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_protect_from_one_philo_table(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;

	ft_get_monitor(&saved_monitor);
	while (saved_monitor->philos[philo_number - 1].left_fork->number
		== saved_monitor->philos[philo_number - 1].right_fork->number)
	{
		usleep(1000);
		if (ft_is_dinner_finished(philo_number))
			return (1);
	}
	return (0);
}

void	ft_check_meal(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;

	ft_get_monitor(&saved_monitor);
	if (saved_monitor->philos[philo_number - 1]
		.params.number_of_times_each_philosopher_must_eat == NOTSET)
	{
		return ;
	}
	if (saved_monitor->philos[philo_number - 1]
		.params.number_of_times_each_philosopher_must_eat
		<= saved_monitor->philos[philo_number - 1].meals)
	{
		pthread_mutex_lock(&(saved_monitor->monitor_mutex));
		saved_monitor->philos[philo_number - 1].state = FULL;
		pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
	}
}

void	ft_check_if_available(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;
	t_bool				is_legable_to_eat;

	ft_get_monitor(&saved_monitor);
	is_legable_to_eat = ft_get_current_philo_state(philo_number) == HUNGRY;
	if (is_legable_to_eat)
	{
		if (ft_protect_from_one_philo_table(philo_number))
			return ;
		if (ft_is_dinner_finished(philo_number))
			return ;
		ft_change_fork_state(
			saved_monitor->philos[philo_number - 1].left_fork, TRUE);
		ft_change_philo_state(philo_number, GOTFORK);
		ft_print_state(philo_number);
		if (ft_is_dinner_finished(philo_number))
			return ;
		ft_change_fork_state(
			saved_monitor->philos[philo_number - 1].right_fork, TRUE);
		ft_change_philo_state(philo_number, GOTFORK);
		ft_print_state(philo_number);
		if (ft_is_dinner_finished(philo_number))
			return ;
		ft_change_philo_state(philo_number, EATING);
	}
}
