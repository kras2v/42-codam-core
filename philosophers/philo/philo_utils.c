/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:19:03 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/07 13:05:06 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static unsigned int	ft_get_max(unsigned int first, unsigned int second)
{
	if (first >= second)
		return (first);
	return (second);
}

static void	ft_init_philo_params(t_philo_params *philo_params)
{
	philo_params->number_of_philosophers = 0;
	philo_params->time_to_die = 0;
	philo_params->time_to_eat = 0;
	philo_params->time_to_sleep = 0;
	philo_params->number_of_times_each_philosopher_must_eat = NOTSET;
}

static void	ft_get_sleep_gap_and_fork_retry_time(t_philo_params *philo_params)
{
	long	diff;
	long	max_value;
	int		uneven;

	max_value = (long)ft_get_max(philo_params->time_to_eat,
			philo_params->time_to_sleep);
	uneven = philo_params->number_of_philosophers % 2 == 1;
	diff = (long)philo_params->time_to_die - max_value * (2 + uneven);
	if (diff <= 10)
	{
		philo_params->sleep_gap = diff / 4;
		if (philo_params->sleep_gap < 0)
			philo_params->sleep_gap = 0;
	}
	else
	{
		philo_params->sleep_gap = 10;
	}
	philo_params->sleep_gap *= 1000;
	philo_params->ask_fork_retry = philo_params->sleep_gap / 10;
}

int	ft_assign_philo_params(char **argv, t_philo_params *philo_params)
{
	long			result;
	size_t			i;

	i = 0;
	ft_init_philo_params(philo_params);
	while (argv[i] != NULL)
	{
		result = ft_validate_number_input(argv[i]);
		if (result < 0)
			return (FAIL);
		if (i == 0)
			philo_params->number_of_philosophers = result;
		else if (i == 1)
			philo_params->time_to_die = result;
		else if (i == 2)
			philo_params->time_to_eat = result;
		else if (i == 3)
			philo_params->time_to_sleep = result;
		else if (i == 4)
			philo_params->number_of_times_each_philosopher_must_eat = result;
		i++;
	}
	ft_get_sleep_gap_and_fork_retry_time(philo_params);
	return (OK);
}

t_philo	*ft_assign_philos(t_philo_params philo_params)
{
	t_philo	*philos;
	size_t	i;

	philos = ft_calloc((philo_params.number_of_philosophers), sizeof(t_philo));
	if (philos == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < philo_params.number_of_philosophers)
	{
		(philos + i)->number = i + 1;
		(philos + i)->params = philo_params;
		(philos + i)->left_fork = NULL;
		(philos + i)->right_fork = NULL;
		(philos + i)->last_meal = 0;
		(philos + i)->state = THINKING;
		i++;
	}
	return (philos);
}
