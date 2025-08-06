/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:26:14 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/08 13:27:45 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_try_take_a_fork(
		unsigned int philo_number, t_fork *fork, t_monitor *saved_monitor)
{
	while (TRUE)
	{
		if (ft_is_dinner_finished(philo_number, saved_monitor))
			return ;
		if (ft_is_fork_released(fork))
			break ;
		usleep(saved_monitor->philos[philo_number - 1].params.ask_fork_retry);
	}
}

t_bool	ft_is_fork_released(t_fork *fork)
{
	t_bool	locked;

	pthread_mutex_lock(&(fork->mutex));
	locked = fork->locked;
	pthread_mutex_unlock(&(fork->mutex));
	if (locked == FALSE)
	{
		return (TRUE);
	}
	return (FALSE);
}

void	ft_put_forks(unsigned int philo_number, t_monitor *saved_monitor)
{
	ft_change_fork_state(
		saved_monitor->philos[philo_number - 1].right_fork, FALSE);
	ft_change_fork_state(
		saved_monitor->philos[philo_number - 1].left_fork, FALSE);
	if (ft_is_dinner_finished(philo_number, saved_monitor))
		return ;
}

int	ft_init_forks(t_philo *philos, t_monitor *monitor)
{
	size_t	i;

	i = 0;
	while (i < philos->params.number_of_philosophers)
	{
		(monitor->forks + i)->locked = FALSE;
		(monitor->forks + i)->number = i + 1;
		if (pthread_mutex_init(&((monitor->forks + i)->mutex), NULL) == -1)
		{
			ft_puterror("Error joining thread");
			return (ft_cleanup_forks(monitor, i), FAIL);
		}
		i++;
	}
	i = 0;
	while (i < monitor->philos->params.number_of_philosophers)
	{
		(monitor->philos + i)->left_fork = monitor->forks + i;
		if (i == monitor->philos->params.number_of_philosophers - 1)
			(monitor->philos + i)->right_fork = monitor->forks;
		else
			(monitor->philos + i)->right_fork = monitor->forks + i + 1;
		i++;
	}
	return (OK);
}

void	ft_take_fork(unsigned int philo_number, t_monitor *saved_monitor)
{
	if (ft_is_dinner_finished(philo_number, saved_monitor))
		return ;
	ft_change_philo_state(philo_number, HUNGRY, saved_monitor);
	ft_try_take_a_fork(philo_number,
		saved_monitor->philos[philo_number - 1].left_fork, saved_monitor);
	ft_try_take_a_fork(philo_number,
		saved_monitor->philos[philo_number - 1].right_fork, saved_monitor);
	if (ft_is_dinner_finished(philo_number, saved_monitor))
		return ;
	ft_check_if_available(philo_number, saved_monitor);
}
