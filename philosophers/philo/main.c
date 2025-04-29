/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:18:25 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/29 16:18:23 by kvalerii         ###   ########.fr       */
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
	else if (philo->state == FORK)
	{
		printf("%ld %d has taken a fork\n", get_current_time(), philo->number);
	}
	pthread_mutex_unlock(philo->print_state_mutex);
}

void	check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->death_checker_mutex);
	if (philo->params.time_to_die <= get_current_time() - philo->last_meal)
	{
		*(philo->is_someone_dead) = true;
		philo->state = DIE;
		print_state(philo);
	}
	pthread_mutex_unlock(philo->death_checker_mutex);
}

void	check_meals(t_philo *philo)
{
	if (philo->params.number_of_times_each_philosopher_must_eat == -42)
		return ;
	pthread_mutex_lock(philo->meals_checker_mutex);
	if (philo->meals >= philo->params.number_of_times_each_philosopher_must_eat)
	{
		philo->state = FULL;
	}
	pthread_mutex_unlock(philo->meals_checker_mutex);
}

void	*routine2(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_current_time();
	check_death(philo);
	if (*(philo->is_someone_dead))
	{
		return (NULL);
	}
	// if (philo->number % 2 == 0)
	// {
	// 	usleep(philo->params.time_to_die / 2);
	// }
	while (1)
	{
		if (*(philo->everyone_at_the_table) == true)
		{
			print_state(philo);
			check_death(philo);
			if (*(philo->is_someone_dead))
			{
				return (NULL);
			}
			while (1)
			{
				pthread_mutex_lock(&(philo->left_fork->mutex));
				if (philo->left_fork->locked == true)
				{
					//?TRY GET LEFT FORK
					pthread_mutex_unlock(&(philo->left_fork->mutex));
					usleep(100);
					check_death(philo);
					if (*(philo->is_someone_dead))
					{
						return (NULL);
					}
					continue;
				}
				philo->left_fork->locked = true;
				philo->state = FORK;
				print_state(philo);
				if (philo->right_fork->number == philo->left_fork->number)
				{
					pthread_mutex_unlock(&(philo->left_fork->mutex));
					continue;
				}
				pthread_mutex_lock(&(philo->right_fork->mutex));
				if (philo->right_fork->locked == true)
				{
					//?RELEASE LEFT FORK
					philo->left_fork->locked = false;
					pthread_mutex_unlock(&(philo->left_fork->mutex));
					usleep(100);
					check_death(philo);
					if (*(philo->is_someone_dead))
					{
						return (NULL);
					}
					continue;
				}
				philo->right_fork->locked = true;
				//?FORK
				philo->state = FORK;
				print_state(philo);
				//?EAT
				philo->state = EAT;
				print_state(philo);
				philo->meals++;
				philo->last_meal = get_current_time();
				usleep(1000 * philo->params.time_to_eat);
				//?RELEASE FORKS
				philo->right_fork->locked = false;
				pthread_mutex_unlock(&(philo->right_fork->mutex));
				philo->left_fork->locked = false;
				pthread_mutex_unlock(&(philo->left_fork->mutex));
				//?CHECK IF FULL
				check_meals(philo);
				if (philo->state == FULL)
				{
					return (NULL);
				}
				//?CHECK DEATH BEFORE SLEEP
				check_death(philo);
				if (*(philo->is_someone_dead))
				{
					return (NULL);
				}
				//?SLEEP
				philo->state = SLEEP;
				print_state(philo);
				usleep(1000 * philo->params.time_to_sleep);
				//?CHECK DEATH WHEN AWAKE
				check_death(philo);
				if (*(philo->is_someone_dead))
				{
					return (NULL);
				}
				//?THINK
				philo->state = THINK;
			}
		}
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_current_time();
	check_death(philo);
	if (*(philo->is_someone_dead))
	{
		return (NULL);
	}
	while (1)
	{
		if (*(philo->everyone_at_the_table) == true)
		{
			print_state(philo);
			if (philo->number % 2 == 0)
			{
				usleep(philo->params.time_to_die / 2);
			}
			check_death(philo);
			if (*(philo->is_someone_dead))
			{
				return (NULL);
			}
			while (philo->left_fork->locked == true)
			{
				usleep(1);
				check_death(philo);
				if (*(philo->is_someone_dead))
				{
					return (NULL);
				}
			}
			if (philo->left_fork->locked == false)
			{
				pthread_mutex_lock(&(philo->left_fork->mutex));
				philo->left_fork->locked = true;
				philo->state = FORK;
				print_state(philo);
				while (philo->right_fork->locked == true)
				{
					usleep(1);
					check_death(philo);
					if (*(philo->is_someone_dead))
					{
						return (NULL);
					}
				}
				if (philo->right_fork->locked == false)
				{
					pthread_mutex_lock(&(philo->right_fork->mutex));
					philo->right_fork->locked = true;
					philo->state = FORK;
					print_state(philo);
					philo->state = EAT;
					print_state(philo);
					philo->meals++;
					philo->last_meal = get_current_time();
					usleep(1000 * philo->params.time_to_eat);
					philo->right_fork->locked = false;
					pthread_mutex_unlock(&(philo->right_fork->mutex));
				}
				philo->left_fork->locked = false;
				pthread_mutex_unlock(&(philo->left_fork->mutex));
				check_meals(philo);
				if (philo->state == FULL)
				{
					return (NULL);
				}
				check_death(philo);
				if (*(philo->is_someone_dead))
				{
					return (NULL);
				}
				philo->state = SLEEP;
				print_state(philo);
				usleep(1000 * philo->params.time_to_sleep);
				check_death(philo);
				if (*(philo->is_someone_dead))
				{
					return (NULL);
				}
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
		(philo_routine->philos + i)->is_someone_dead = &philo_routine->is_someone_dead;
		(philo_routine->philos + i)->print_state_mutex = &philo_routine->print_state_mutex;
		(philo_routine->philos + i)->death_checker_mutex = &philo_routine->death_checker_mutex;
		(philo_routine->philos + i)->meals_checker_mutex = &philo_routine->meals_checker_mutex;
		(philo_routine->philos + i)->left_fork = philo_routine->forks + i;
		if (i == 0)
		{
			(philo_routine->philos + i)->right_fork = philo_routine->forks + philo_routine->philos->params.number_of_philosophers - 1;
		}
		else
		{
			(philo_routine->philos + i)->right_fork = philo_routine->forks + i - 1;
		}
		i++;
	}
	i = 0;
	while (i < philo_routine->philos->params.number_of_philosophers)
	{
		if (pthread_create(&(philo_routine->philos + i)->thread, NULL, &routine2, (philo_routine->philos + i)) != 0)
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

	routine->is_someone_dead = false;
	routine->everyone_at_the_table = false;
	routine->philos = philos;
	pthread_mutex_init(&routine->print_state_mutex, NULL);
	pthread_mutex_init(&routine->death_checker_mutex, NULL);
	pthread_mutex_init(&routine->meals_checker_mutex, NULL);
	routine->forks = ft_calloc(philos->params.number_of_philosophers, sizeof(t_fork));
	if (routine->forks == NULL)
	{
		return (FAIL);
	}
	i = 0;
	while (i < philos->params.number_of_philosophers)
	{
		(routine->forks + i)->locked = false;
		(routine->forks + i)->number = i + 1;
		pthread_mutex_init(&((routine->forks + i)->mutex), NULL);
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
