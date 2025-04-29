/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:18:25 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/29 11:21:43 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo_params(t_philo_params *philo_params)
{
	philo_params->number_of_philosophers = 0;
	philo_params->time_to_die = 0;
	philo_params->time_to_eat = 0;
	philo_params->time_to_sleep = 0;
	philo_params->number_of_times_each_philosopher_must_eat = -42;
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
	ft_print_philo_params(*philo_params);
	return (OK);
}

long	get_current_time()
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	print_state(t_philo *philo)
{
	pthread_mutex_lock(philo->print_state_mutex);
	if (philo->state == THINK)
	{
		printf("%ld %d is thinking\n", get_current_time(), philo->number);
	}
	else if (philo->state == EAT)
	{
		printf("%ld %d is eating\n", get_current_time(), philo->number);
	}
	else if (philo->state == SLEEP)
	{
		printf("%ld %d is sleeping\n", get_current_time(), philo->number);
	}
	else if (philo->state == DIE)
	{
		printf("%ld %d died\n", get_current_time(), philo->number);
	}
	pthread_mutex_unlock(philo->print_state_mutex);
}

void	*routine(void *arg)
{
	t_philo			*philo;
	int				meals_count;

	meals_count = 0;
	philo = (t_philo *)arg;
	philo->last_meal = get_current_time();
	print_state(philo);
	while (meals_count != 3)
	{
		if (*(philo->everyone_at_the_table) == true)
		{
			if (philo->params.number_of_philosophers % 2 == 0)
			{
				usleep(philo->params.time_to_eat / 2);
			}
			if (philo->left_fork->locked == false)
			{
				pthread_mutex_lock(philo->left_fork_mutex);
				philo->left_fork->locked = true;
				if (philo->right_fork->locked == false)
				{
					pthread_mutex_lock(philo->right_fork_mutex);
					philo->right_fork->locked = true;
					philo->state = EAT;
					print_state(philo);
					meals_count++;
					usleep(1000 * philo->params.time_to_eat);
					philo->right_fork->locked = false;
					pthread_mutex_unlock(philo->right_fork_mutex);
				}
				philo->left_fork->locked = false;
				pthread_mutex_unlock(philo->left_fork_mutex);
				philo->state = SLEEP;
				print_state(philo);
				usleep(1000 * philo->params.time_to_sleep);
				philo->state = THINK;
				print_state(philo);
			}
		}
	}
	return (NULL);
}

int	ft_create_threads(t_philo_routine *philo_routine)
{
	size_t	i;

	i = 0;
	while (i < philo_routine->philos->params.number_of_philosophers)
	{
		(philo_routine->philos + i)->everyone_at_the_table = &philo_routine->everyone_at_the_table;
		(philo_routine->philos + i)->print_state_mutex = &philo_routine->print_state_mutex;
		(philo_routine->philos + i)->forks_mutex = philo_routine->forks_mutex;
		(philo_routine->philos + i)->forks = philo_routine->forks;
		(philo_routine->philos + i)->left_fork = philo_routine->forks + i;
		(philo_routine->philos + i)->left_fork_mutex = philo_routine->forks_mutex + i;
		if (i == 0)
		{
			(philo_routine->philos + i)->right_fork = philo_routine->forks + philo_routine->philos->params.number_of_philosophers - 1;
			(philo_routine->philos + i)->right_fork_mutex = philo_routine->forks_mutex + philo_routine->philos->params.number_of_philosophers - 1;
		}
		else
		{
			(philo_routine->philos + i)->right_fork = philo_routine->forks + i - 1;
			(philo_routine->philos + i)->right_fork_mutex = philo_routine->forks_mutex + i - 1;
		}
		i++;
	}
	i = 0;
	while (i < philo_routine->philos->params.number_of_philosophers)
	{
		if (pthread_create(&(philo_routine->philos + i)->thread, NULL, &routine, (philo_routine->philos + i)) != 0)
		{
			ft_puterror("Error creating thread");
		}
		i++;
	}
	i = 0;
	philo_routine->everyone_at_the_table = true;
	while (i < philo_routine->philos->params.number_of_philosophers)
	{
		if (pthread_join((philo_routine->philos + i)->thread, NULL) != 0)
		{
			ft_puterror("Error joining thread");
		}
		i++;
	}
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
		(philos + i)->everyone_at_the_table = NULL;
		(philos + i)->last_meal = 0;
		(philos + i)->state = THINK;
		i++;
	}
	return (philos);
}

int	ft_assign_philo_routine(t_philo_routine *routine, t_philo *philos)
{
	size_t	i;

	routine->everyone_at_the_table = false;
	routine->philos = philos;
	routine->portions_eaten = 0;
	pthread_mutex_init(&routine->print_state_mutex, NULL);
	pthread_mutex_init(&routine->portions_eaten_mutex, NULL);
	routine->forks = ft_calloc(philos->params.number_of_philosophers, sizeof(t_fork));
	if (routine->forks == NULL)
	{
		routine->forks_mutex = NULL;
		return (FAIL);
	}
	i = 0;
	while (i < philos->params.number_of_philosophers)
	{
		(routine->forks + i)->locked = false;
		(routine->forks + i)->number = i + 1;
		i++;
	}
	routine->forks_mutex = ft_calloc(philos->params.number_of_philosophers, sizeof(pthread_mutex_t));
	if (routine->forks_mutex == NULL)
	{
		return (FAIL);
	}
	i = 0;
	while (i < philos->params.number_of_philosophers)
	{
		pthread_mutex_init((routine->forks_mutex + i), NULL);
		i++;
	}
	return (OK);
}

int	main(int argc, char **argv)
{
	t_philo_routine	philo_routine;
	t_philo_params	philo_params;
	t_philo			*philos;

	if (argc != 5 && argc != 6)
	{
		ft_print_info_message();
		return (EXIT_FAILURE);
	}
	(void)argv;
	if (ft_assign_philo_params(argv + 1, &philo_params) == FAIL)
	{
		ft_print_info_message();
		return (EXIT_FAILURE);
	}
	philos = ft_assign_philos(philo_params);
	if (philos == NULL)
	{
		return (EXIT_FAILURE);
	}
	if (ft_assign_philo_routine(&philo_routine, philos) == FAIL)
	{
		ft_cleanup_routine(&philo_routine);
		return (EXIT_FAILURE);
	}
	ft_create_threads(&philo_routine);
	ft_cleanup_routine(&philo_routine);
}
