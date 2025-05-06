/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:18:25 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/05 15:10:15 by valeriia         ###   ########.fr       */
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

unsigned int	get_max(unsigned int first, unsigned int second)
{
	if (first >= second)
		return (first);
	return (second);
}

int	ft_assign_philo_params(char **argv, t_philo_params *philo_params)
{
	long			result;
	long			diff;
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
	if (philo_params->number_of_philosophers % 2 == 0)
		diff = (long)philo_params->time_to_die - (long)get_max(philo_params->time_to_eat, philo_params->time_to_sleep) * 2;
	else
		diff = (long)philo_params->time_to_die - (long)get_max(philo_params->time_to_eat, philo_params->time_to_sleep) * 3;
	if (diff <= 10)
	{
		philo_params->sleep_gap = diff / 4;
		if (philo_params->sleep_gap < 0)
		{
			philo_params->sleep_gap = 0;
		}
		philo_params->sleep_gap *= 1000;
	}
	else
	{
		philo_params->sleep_gap = 10000;
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

t_monitor	*set_and_get_monitor(t_monitor *monitor)
{
	static t_monitor	*saved_monitor;

	if (monitor == NULL)
	{
		return (saved_monitor);
	}
	if (saved_monitor == NULL)
	{
		saved_monitor = monitor;
	}
	return (saved_monitor);
}

void	print_state(t_philo *philo)
{
	static t_monitor	*saved_monitor;
	t_state				state;

	if (saved_monitor == NULL)
	{
		saved_monitor = set_and_get_monitor(NULL);
		return ;
	}

	pthread_mutex_lock(&(saved_monitor->print_state_mutex));
	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	state = philo->state;
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
	if (state == THINKING)
	{
		printf("%ld %d is thinking\n", get_current_time(), philo->number);
	}
	else if (state == EATING)
	{
		printf("%ld %d is eating\n", get_current_time(), philo->number);
	}
	else if (state == SLEEPING)
	{
		printf("%ld %d is sleeping\n", get_current_time(), philo->number);
	}
	else if (state == DIED)
	{
		printf("%ld %d died\n", get_current_time(), philo->number);
	}
	else if (state == GOTFORK)
	{
		printf("%ld %d has taken a fork\n", get_current_time(), philo->number);
	}
	pthread_mutex_unlock(&(saved_monitor->print_state_mutex));
}

void	check_death(t_philo *philo)
{
	static t_monitor	*saved_monitor;
	size_t				i;

	if (saved_monitor == NULL)
	{
		saved_monitor = set_and_get_monitor(NULL);
		return ;
	}

	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	if (saved_monitor->is_someone_dead == true)
	{
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		return ;
	}
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

	if (philo->params.time_to_die <= get_current_time() - philo->last_meal)
	{
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		philo->state = DIED;
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		saved_monitor->is_someone_dead = true;
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

		print_state(philo);

		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		i = 0;
		while (i < philo->params.number_of_philosophers)
		{
			(saved_monitor->philos[i]).state = FINISH;
			i++;
		}
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
	}
}

void	check_meal(t_philo *philo)
{
	static t_monitor	*saved_monitor;

	if (saved_monitor == NULL)
	{
		saved_monitor = set_and_get_monitor(NULL);
		return ;
	}
	if (philo->params.number_of_times_each_philosopher_must_eat == -42)
	{
		return ;
	}
	if (philo->params.number_of_times_each_philosopher_must_eat <= philo->meals)
	{
		pthread_mutex_lock(&(saved_monitor->death_checker_mutex));
		philo->state = FULL;
		pthread_mutex_unlock(&(saved_monitor->death_checker_mutex));
	}
}

int	left_nbr_i(t_philo philo)
{
	if (philo.number == 1)
		return (philo.params.number_of_philosophers);
	else
		return (philo.number - 1);
}

int	right_nbr_i(t_philo philo)
{
	if (philo.number == philo.params.number_of_philosophers)
		return (1);
	else
		return (philo.number + 1);
}

void	check_if_available(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;
	bool				is_legable_to_eat;

	if (saved_monitor == NULL)
	{
		saved_monitor = set_and_get_monitor(NULL);
		return ;
	}
	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	is_legable_to_eat = saved_monitor->philos[philo_number - 1].state == HUNGRY
	&& saved_monitor->philos[right_nbr_i(saved_monitor->philos[philo_number - 1]) - 1].state != EATING
	&& saved_monitor->philos[left_nbr_i(saved_monitor->philos[philo_number - 1]) - 1].state != EATING;
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
	if (is_legable_to_eat)
	{
		check_death(&(saved_monitor->philos[philo_number - 1]));
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		if (saved_monitor->philos[philo_number - 1].state == FINISH)
		{
			pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
			return ;
		}
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));


		pthread_mutex_lock(&(saved_monitor->philos[philo_number - 1].left_fork->mutex));
		saved_monitor->philos[philo_number - 1].left_fork->locked = true;
		// printf("took left fork %d\n", philo_number); 
		pthread_mutex_unlock(&(saved_monitor->philos[philo_number - 1].left_fork->mutex));

		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		saved_monitor->philos[philo_number - 1].state = GOTFORK;
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

		print_state(&(saved_monitor->philos[philo_number - 1]));

		check_death(&(saved_monitor->philos[philo_number - 1]));
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		if (saved_monitor->philos[philo_number - 1].state == FINISH)
		{
			pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
			return ;
		}
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

		while (saved_monitor->philos[philo_number - 1].left_fork->number
			==  saved_monitor->philos[philo_number - 1].right_fork->number)
		{
			usleep(1000);
			check_death(&(saved_monitor->philos[philo_number - 1]));
			if (saved_monitor->philos[philo_number - 1].state == FINISH)
			{
				return ;
			}
		}

		pthread_mutex_lock(&(saved_monitor->philos[philo_number - 1].right_fork->mutex));
		saved_monitor->philos[philo_number - 1].right_fork->locked = true;
		// printf("took right fork %d\n", philo_number);
		pthread_mutex_unlock(&(saved_monitor->philos[philo_number - 1].right_fork->mutex));
	
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		saved_monitor->philos[philo_number - 1].state = GOTFORK;
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

		print_state(&(saved_monitor->philos[philo_number - 1]));

		check_death(&(saved_monitor->philos[philo_number - 1]));
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		if (saved_monitor->philos[philo_number - 1].state == FINISH)
		{
			pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
			return ;
		}
		saved_monitor->philos[philo_number - 1].state = EATING;
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
	}
}

void	take_fork(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;

	if (saved_monitor == NULL)
	{
		saved_monitor = set_and_get_monitor(NULL);
		return;
	}
	check_death(&(saved_monitor->philos[philo_number - 1]));
	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	if (saved_monitor->philos[philo_number - 1].state == FINISH)
	{
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		return ;
	}
	saved_monitor->philos[philo_number - 1].state = HUNGRY;
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
	// printf("tries take fork %d\n", philo_number);
	while (true)
	{
		check_death(&(saved_monitor->philos[philo_number - 1]));
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		if (saved_monitor->philos[philo_number - 1].state == FINISH)
		{
			pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
			return ;
		}
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

		pthread_mutex_lock(&(saved_monitor->philos[philo_number - 1].left_fork->mutex));
		if (saved_monitor->philos[philo_number - 1].left_fork->locked == false)
		{
			pthread_mutex_unlock(&(saved_monitor->philos[philo_number - 1].left_fork->mutex));
			break;
		}
		pthread_mutex_unlock(&(saved_monitor->philos[philo_number - 1].left_fork->mutex));

		usleep(1000);
	}
	while (true)
	{

		check_death(&(saved_monitor->philos[philo_number - 1]));
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		if (saved_monitor->philos[philo_number - 1].state == FINISH)
		{
			pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
			return ;
		}
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

		pthread_mutex_lock(&(saved_monitor->philos[philo_number - 1].right_fork->mutex));
		if (saved_monitor->philos[philo_number - 1].right_fork->locked == false)
		{
			pthread_mutex_unlock(&(saved_monitor->philos[philo_number - 1].right_fork->mutex));
			break;
		}
		pthread_mutex_unlock(&(saved_monitor->philos[philo_number - 1].right_fork->mutex));

		usleep(1000);
	}
	check_death(&(saved_monitor->philos[philo_number - 1]));
	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	if (saved_monitor->philos[philo_number - 1].state == FINISH)
	{
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		return ;
	}
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
	// printf("waited until getting fork %d\n", philo_number);
	check_if_available(philo_number);
}

bool	wait_until_start_eating()
{
	static t_monitor	*saved_monitor;
	bool				everyone_at_the_table;

	if (saved_monitor == NULL)
	{
		saved_monitor = set_and_get_monitor(NULL);
		return (false);
	}
	while (true)
	{
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		everyone_at_the_table = saved_monitor->everyone_at_the_table;
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		if (everyone_at_the_table == true)
		{
			break;
		}
		usleep(1000);
	}
	return (true);
}

void	eat(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;

	if (saved_monitor == NULL)
	{
		saved_monitor = set_and_get_monitor(NULL);
		return ;
	}
	check_death(&(saved_monitor->philos[philo_number - 1]));
	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	if (saved_monitor->philos[philo_number - 1].state == FINISH)
	{
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		return ;
	}
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

	print_state(&(saved_monitor->philos[philo_number - 1]));

	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	saved_monitor->philos[philo_number - 1].meals++;
	saved_monitor->philos[philo_number - 1].last_meal = get_current_time();
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

	usleep(1000 * saved_monitor->philos[philo_number - 1].params.time_to_eat);

	check_death(&(saved_monitor->philos[philo_number - 1]));
	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	if (saved_monitor->philos[philo_number - 1].state == FINISH)
	{
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		return ;
	}
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
}

void	psleep(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;

	if (saved_monitor == NULL)
	{
		saved_monitor = set_and_get_monitor(NULL);
		return ;
	}

	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	saved_monitor->philos[philo_number - 1].state = SLEEPING;
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

	check_death(&(saved_monitor->philos[philo_number - 1]));
	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	if (saved_monitor->philos[philo_number - 1].state == FINISH)
	{
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		return ;
	}
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

	print_state(&(saved_monitor->philos[philo_number - 1]));
	usleep(1000 * saved_monitor->philos[philo_number - 1].params.time_to_sleep);
	
	check_death(&(saved_monitor->philos[philo_number - 1]));

	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	if (saved_monitor->philos[philo_number - 1].state == FINISH)
	{
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		return ;
	}
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
}

void	think(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;

	if (saved_monitor == NULL)
	{
		saved_monitor = set_and_get_monitor(NULL);
		return ;
	}

	check_death(&(saved_monitor->philos[philo_number - 1]));
	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	if (saved_monitor->philos[philo_number - 1].state == FINISH)
	{
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		return ;
	}
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));

	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	if (saved_monitor->philos[philo_number - 1].state == SLEEPING)
	{
		saved_monitor->philos[philo_number - 1].state = THINKING;
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		print_state(&(saved_monitor->philos[philo_number - 1]));
		if (saved_monitor->philos[philo_number - 1].params.sleep_gap != 0)
			usleep(saved_monitor->philos[philo_number - 1].params.sleep_gap);
	}
	else
	{
		saved_monitor->philos[philo_number - 1].state = THINKING;
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		print_state(&(saved_monitor->philos[philo_number - 1]));
	}

	check_death(&(saved_monitor->philos[philo_number - 1]));
	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	if (saved_monitor->philos[philo_number - 1].state == FINISH)
	{
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		return ;
	}
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
}

void	put_forks(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;
	
	if (saved_monitor == NULL)
	{
		saved_monitor = set_and_get_monitor(NULL);
		return;
	}

	pthread_mutex_lock(&(saved_monitor->philos[philo_number - 1].right_fork->mutex));
	saved_monitor->philos[philo_number - 1].right_fork->locked = false;
	pthread_mutex_unlock(&(saved_monitor->philos[philo_number - 1].right_fork->mutex));

	pthread_mutex_lock(&(saved_monitor->philos[philo_number - 1].left_fork->mutex));
	saved_monitor->philos[philo_number - 1].left_fork->locked = false;
	pthread_mutex_unlock(&(saved_monitor->philos[philo_number - 1].left_fork->mutex));

	check_death(&(saved_monitor->philos[philo_number - 1]));
	pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
	if (saved_monitor->philos[philo_number - 1].state == FINISH)
	{
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		return ;
	}
	pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
	// usleep(1000);
}

void	*routine(void *arg)
{
	static t_monitor	*saved_monitor;
	t_philo	*philo;

	if (saved_monitor == NULL)
	{
		saved_monitor = set_and_get_monitor(NULL);
		return (NULL);
	}

	philo = (t_philo *)arg;
	philo->last_meal = get_current_time();
	wait_until_start_eating();
	print_state(philo);
	if (philo->number % 2 == 0)
	{
		usleep((philo->params.time_to_die / 2) * 1000);
	}
	while (1)
	{
		take_fork(philo->number);
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		if (philo->state == FINISH)
		{
			pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
			return (NULL);
		}
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		eat(philo->number);
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		if (philo->state == FINISH)
		{
			pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
			return (NULL);
		}
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		put_forks(philo->number);
		check_meal(philo);
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		if (philo->state == FULL)
		{
			pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
			return (NULL);
		}
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		if (philo->state == FINISH)
		{
			pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
			return (NULL);
		}
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		psleep(philo->number);
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		if (philo->state == FINISH)
		{
			pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
			return (NULL);
		}
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
		think(philo->number);
		pthread_mutex_lock(&(saved_monitor->critical_region_mtx));
		if (philo->state == FINISH)
		{
			pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
			return (NULL);
		}
		pthread_mutex_unlock(&(saved_monitor->critical_region_mtx));
	}
	return (NULL);
}

int	ft_create_threads(t_monitor *monitor)
{
	size_t	i;

	i = 0;
	set_and_get_monitor(monitor);
	wait_until_start_eating();
	check_if_available(0);
	print_state(NULL);
	check_death(NULL);
	take_fork(0);
	check_meal(NULL);
	put_forks(0);
	eat(0);
	psleep(0);
	think(0);
	routine(NULL);
	while (i < monitor->philos->params.number_of_philosophers)
	{
		(monitor->philos + i)->left_fork = monitor->forks + i;
		if (i == monitor->philos->params.number_of_philosophers - 1)
		{
			(monitor->philos + i)->right_fork = monitor->forks;
		}
		else
		{
			(monitor->philos + i)->right_fork = monitor->forks + i + 1;
		}
		// printf("philo %d left %d right %d\n", (monitor->philos + i)->number, (monitor->philos + i)->left_fork->number, (monitor->philos + i)->right_fork->number);
		i++;
	}
	i = 0;
	while (i < monitor->philos->params.number_of_philosophers)
	{
		if (pthread_create(&(monitor->philos + i)->thread, NULL, &routine, (monitor->philos + i)) != 0)
		{
			ft_puterror("Error creating thread");
		}
		i++;
	}
	i = 0;
	pthread_mutex_lock(&(monitor->critical_region_mtx));
	monitor->everyone_at_the_table = true;
	pthread_mutex_unlock(&(monitor->critical_region_mtx));
	while (i < monitor->philos->params.number_of_philosophers)
	{
		if (pthread_join((monitor->philos + i)->thread, NULL) != 0)
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
		(philos + i)->last_meal = 0;
		(philos + i)->state = THINKING;
		i++;
	}
	return (philos);
}

t_monitor	*ft_assign_monitor(t_philo *philos)
{
	t_monitor *monitor;
	size_t	i;

	monitor = ft_calloc(1, sizeof(t_monitor));
	if (monitor == NULL)
	{
		return (NULL);
	}
	monitor->philos = philos;
	pthread_mutex_init(&monitor->print_state_mutex, NULL);
	pthread_mutex_init(&monitor->critical_region_mtx, NULL);
	pthread_mutex_init(&monitor->death_checker_mutex, NULL);
	pthread_mutex_init(&monitor->check_fork_mutex, NULL);
	monitor->forks = ft_calloc(philos->params.number_of_philosophers, sizeof(t_fork));
	if (monitor->forks == NULL)
	{
		pthread_mutex_destroy(&monitor->print_state_mutex);
		pthread_mutex_destroy(&monitor->critical_region_mtx);
		pthread_mutex_destroy(&monitor->death_checker_mutex);
		pthread_mutex_destroy(&monitor->check_fork_mutex);
		free(monitor);
		return (NULL);
	}
	i = 0;
	while (i < philos->params.number_of_philosophers)
	{
		(monitor->forks + i)->locked = false;
		(monitor->forks + i)->number = i + 1;
		pthread_mutex_init(&((monitor->forks + i)->mutex), NULL);
		i++;
	}
	return (monitor);
}

int	main(int argc, char **argv)
{
	t_monitor		*monitor;
	t_philo			*philos;
	t_philo_params	philo_params;

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
	monitor = ft_assign_monitor(philos);
	if (monitor == NULL)
	{
		// ft_cleanup_waiter(&monitor);
		return (EXIT_FAILURE);
	}
	ft_create_threads(monitor);
	ft_cleanup_waiter(monitor);
}
