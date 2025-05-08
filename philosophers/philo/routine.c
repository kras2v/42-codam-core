/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:20:05 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/08 10:21:00 by valeriia         ###   ########.fr       */
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

static int	ft_is_state_finish(t_philo *philo)
{
	t_state				state;

	state = ft_get_current_philo_state(philo->number);
	if (state == FINISH || state == FULL)
		return (TRUE);
	return (FALSE);
}

static int	ft_proceed_request_monitor(unsigned int philo_number, t_request request)
{
	static t_monitor	*saved_monitor;

	if (saved_monitor == NULL)
	{
		ft_get_monitor(&saved_monitor);
		return (OK);
	}
	ft_take_fork(philo->number);
	if (ft_is_state_finish(philo))
		return (FAIL);
	ft_eat(philo->number);
	if (ft_is_state_finish(philo))
		return (FAIL);
	ft_put_forks(philo->number);
	ft_check_meal(philo->number);
	if (ft_is_state_finish(philo))
		return (FAIL);
	ft_psleep(philo->number);
	if (ft_is_state_finish(philo))
		return (FAIL);
	ft_think(philo->number);
	if (ft_is_state_finish(philo))
		return (FAIL);
	return (OK);
}

static int	ft_routine_process(t_philo *philo)
{
	ft_take_fork(philo->number);
	if (ft_is_state_finish(philo))
		return (FAIL);
	ft_eat(philo->number);
	if (ft_is_state_finish(philo))
		return (FAIL);
	ft_put_forks(philo->number);
	ft_check_meal(philo->number);
	if (ft_is_state_finish(philo))
		return (FAIL);
	ft_psleep(philo->number);
	if (ft_is_state_finish(philo))
		return (FAIL);
	ft_think(philo->number);
	if (ft_is_state_finish(philo))
		return (FAIL);
	return (OK);
}

static void	*ft_routine(void *arg)
{
	static t_monitor	*saved_monitor;
	t_philo				*philo;

	ft_get_monitor(&saved_monitor);
	philo = (t_philo *)arg;
	ft_wait_until_start_eating();
	philo->last_meal = ft_get_current_time();
	ft_print_state(philo->number);
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
	ft_save_monitor(monitor);
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
