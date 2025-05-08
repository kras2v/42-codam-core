/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:20:05 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/08 11:09:05 by valeriia         ###   ########.fr       */
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

static int	ft_is_state_finish(unsigned int philo_number, t_monitor *saved_monitor)
{
	t_state	state;

	state = ft_get_current_philo_state(philo_number, saved_monitor);
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
	if (request == 	TO_START_DINNER)
	{
		ft_wait_until_start_eating(saved_monitor);
		ft_print_state(philo_number, saved_monitor);
		return (OK);
	}
	else if (request == TO_GOTFORK)
	{
		ft_take_fork(philo_number, saved_monitor);
	}
	else if (request == TO_EATING)
	{
		ft_eat(philo_number, saved_monitor);
	}
	else if (request == TO_PUTFORK)
	{
		ft_put_forks(philo_number, saved_monitor);
	}
	else if (request == TO_CHECKMEAL)
	{
		ft_check_meal(philo_number, saved_monitor);
	}
	else if (request == TO_SLEEPING)
	{
		ft_psleep(philo_number, saved_monitor);
	}
	else if (request == TO_THINKING)
	{
		ft_think(philo_number, saved_monitor);
	}
	if (ft_is_state_finish(philo_number, saved_monitor))
		return (FAIL);
	return (OK);
}

static int	ft_routine_process(t_philo *philo)
{
	if (ft_proceed_request_monitor(philo->number, TO_GOTFORK) == FAIL)
		return (FAIL);
	if (ft_proceed_request_monitor(philo->number, TO_EATING) == FAIL)
		return (FAIL);
	if (ft_proceed_request_monitor(philo->number, TO_PUTFORK) == FAIL)
		return (FAIL);
	if (ft_proceed_request_monitor(philo->number, TO_CHECKMEAL) == FAIL)
		return (FAIL);
	if (ft_proceed_request_monitor(philo->number, TO_SLEEPING) == FAIL)
		return (FAIL);
	if (ft_proceed_request_monitor(philo->number, TO_THINKING) == FAIL)
		return (FAIL);
	return (OK);
}

static void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
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
	ft_save_monitor(monitor);
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
