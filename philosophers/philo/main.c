/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:18:25 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/06 20:48:51 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo_params(t_philo_params *philo_params)
{
	philo_params->number_of_philosophers = 0;
	philo_params->time_to_die = 0;
	philo_params->time_to_eat = 0;
	philo_params->time_to_sleep = 0;
	philo_params->number_of_times_each_philosopher_must_eat = NOTSET;
}

unsigned int	get_max(unsigned int first, unsigned int second)
{
	if (first >= second)
		return (first);
	return (second);
}

void	ft_get_sleep_gap_and_fork_retry_time(t_philo_params *philo_params)
{
	long	diff;
	long	max_value;
	int		uneven;

	max_value = (long)get_max(philo_params->time_to_eat, philo_params->time_to_sleep);
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
	ft_print_philo_params(*philo_params);
	return (OK);
}

long	get_current_time()
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

t_monitor	*save_monitor(t_monitor *monitor)
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

int	get_monitor(t_monitor **saved_monitor)
{
	if (saved_monitor && (*saved_monitor) == NULL)
	{
		(*saved_monitor) = save_monitor(NULL);
		return (1);
	}
	return (0);
}

t_state	get_current_philo_state(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;
	t_state	state;

	get_monitor(&saved_monitor);
	pthread_mutex_lock(&(saved_monitor->monitor_mutex));
	state = saved_monitor->philos[philo_number - 1].state;
	pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
	return (state);
}

t_state	is_fork_released(t_fork *fork)
{
	static t_monitor	*saved_monitor;
	bool				locked;

	get_monitor(&saved_monitor);
	pthread_mutex_lock(&(fork->mutex));
	locked = fork->locked;
	pthread_mutex_unlock(&(fork->mutex));
	if (locked == false)
	{
		return (true);
	}
	return (false);
}

void	show_philo_action(unsigned int philo_number, char *msg)
{
	static t_monitor	*saved_monitor;

	get_monitor(&saved_monitor);
	printf("%ld %d %s\n", get_current_time(), saved_monitor->philos[philo_number - 1].number, msg);
}

void	print_state(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;
	t_state				state;

	get_monitor(&saved_monitor);
	pthread_mutex_lock(&(saved_monitor->print_state_mutex));
	state = get_current_philo_state(philo_number);
	if (state == THINKING)
		show_philo_action(philo_number, GREEN"is thinking"RESET);
	else if (state == EATING)
		show_philo_action(philo_number, YELLOW"is eating"RESET);
	else if (state == SLEEPING)
		show_philo_action(philo_number, BLUE"is sleeping"RESET);
	else if (state == DIED)
		show_philo_action(philo_number, RED"died"RESET);
	else if (state == GOTFORK)
		show_philo_action(philo_number, MAGENTA"has taken a fork"RESET);
	pthread_mutex_unlock(&(saved_monitor->print_state_mutex));
}

void	check_death(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;
	size_t				i;

	get_monitor(&saved_monitor);
	if (saved_monitor->philos[philo_number - 1].params.time_to_die <= get_current_time() - saved_monitor->philos[philo_number - 1].last_meal)
	{
		pthread_mutex_lock(&(saved_monitor->monitor_mutex));
		saved_monitor->philos[philo_number - 1].state = DIED;
		saved_monitor->is_someone_dead = true;
		pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
		print_state(saved_monitor->philos[philo_number - 1].number);
		pthread_mutex_lock(&(saved_monitor->monitor_mutex));
		i = 0;
		while (i < saved_monitor->philos[philo_number - 1].params.number_of_philosophers)
		{
			(saved_monitor->philos[i]).state = FINISH;
			i++;
		}
		pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
	}
}

void	check_meal(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;

	get_monitor(&saved_monitor);
	if (saved_monitor->philos[philo_number - 1].params.number_of_times_each_philosopher_must_eat == NOTSET)
	{
		return ;
	}
	if (saved_monitor->philos[philo_number - 1].params.number_of_times_each_philosopher_must_eat <= saved_monitor->philos[philo_number - 1].meals)
	{
		pthread_mutex_lock(&(saved_monitor->monitor_mutex));
		saved_monitor->philos[philo_number - 1].state = FULL;
		pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
	}
}

int	is_dinner_finished(unsigned int philo_number)
{
	t_state				state;

	check_death(philo_number);
	state = get_current_philo_state(philo_number);
	if (state == FINISH)
		return (true);
	return (false);
}

void	change_fork_state(t_fork *fork, bool locked)
{
	pthread_mutex_lock(&(fork->mutex));
	fork->locked = locked;
	pthread_mutex_unlock(&(fork->mutex));
}

void	change_philo_state(unsigned int philo_number, t_state state)
{
	static t_monitor	*saved_monitor;

	get_monitor(&saved_monitor);
	pthread_mutex_lock(&(saved_monitor->monitor_mutex));
	saved_monitor->philos[philo_number - 1].state = state;
	pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
}

int	protect_from_one_philo_table(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;

	get_monitor(&saved_monitor);
	while (saved_monitor->philos[philo_number - 1].left_fork->number
		==  saved_monitor->philos[philo_number - 1].right_fork->number)
	{
		usleep(1000);
		if (is_dinner_finished(philo_number))
			return (1);
	}
	return (0);
}

void	check_if_available(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;
	bool				is_legable_to_eat;

	get_monitor(&saved_monitor);
	is_legable_to_eat = get_current_philo_state(philo_number) == HUNGRY;
	if (is_legable_to_eat)
	{
		if (protect_from_one_philo_table(philo_number))
			return ;
		if (is_dinner_finished(philo_number))
			return ;
		change_fork_state(saved_monitor->philos[philo_number - 1].left_fork, true);
		change_philo_state(philo_number, GOTFORK);
		print_state(philo_number);
		if (is_dinner_finished(philo_number))
			return ;
		pthread_mutex_lock(&(saved_monitor->philos[philo_number - 1].right_fork->mutex));
		saved_monitor->philos[philo_number - 1].right_fork->locked = true;
		pthread_mutex_unlock(&(saved_monitor->philos[philo_number - 1].right_fork->mutex));
		change_philo_state(philo_number, GOTFORK);
		print_state(philo_number);
		if (is_dinner_finished(philo_number))
			return ;
		change_philo_state(philo_number, EATING);
	}
}

void	try_take_a_fork(unsigned int philo_number, t_fork *fork)
{
	static t_monitor	*saved_monitor;

	get_monitor(&saved_monitor);
	while (true)
	{
		if (is_dinner_finished(philo_number))
			return ;
		if (is_fork_released(fork))
			break;
		usleep(saved_monitor->philos[philo_number - 1].params.ask_fork_retry);
	}
}

void	take_fork(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;

	get_monitor(&saved_monitor);
	if (is_dinner_finished(philo_number))
		return ;
	change_philo_state(philo_number, HUNGRY);
	try_take_a_fork(philo_number, saved_monitor->philos[philo_number - 1].left_fork);
	try_take_a_fork(philo_number, saved_monitor->philos[philo_number - 1].right_fork);
	if (is_dinner_finished(philo_number))
		return ;
	check_if_available(philo_number);
}

void	wait_until_start_eating()
{
	static t_monitor	*saved_monitor;
	bool				everyone_at_the_table;

	get_monitor(&saved_monitor);
	while (true)
	{
		pthread_mutex_lock(&(saved_monitor->monitor_mutex));
		everyone_at_the_table = saved_monitor->everyone_at_the_table;
		pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
		if (everyone_at_the_table == true)
		{
			break;
		}
		usleep(1000);
	}
	return ;
}

void	eat(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;

	get_monitor(&saved_monitor);
	if (is_dinner_finished(philo_number))
		return ;
	print_state(philo_number);
	pthread_mutex_lock(&(saved_monitor->monitor_mutex));
	saved_monitor->philos[philo_number - 1].meals++;
	saved_monitor->philos[philo_number - 1].last_meal = get_current_time();
	pthread_mutex_unlock(&(saved_monitor->monitor_mutex));
	usleep(1000 * saved_monitor->philos[philo_number - 1].params.time_to_eat);
	if (is_dinner_finished(philo_number))
		return ;
}

void	psleep(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;

	get_monitor(&saved_monitor);
	if (is_dinner_finished(philo_number))
		return ;
	change_philo_state(philo_number, SLEEPING);
	print_state(philo_number);
	usleep(1000 * saved_monitor->philos[philo_number - 1].params.time_to_sleep);
	if (is_dinner_finished(philo_number))
		return ;
}

void	think(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;
	t_state				state;

	get_monitor(&saved_monitor);
	if (is_dinner_finished(philo_number))
		return ;
	state = get_current_philo_state(philo_number);
	change_philo_state(philo_number, THINKING);
	print_state(philo_number);
	if (state == SLEEPING)
	{
		if (saved_monitor->philos[philo_number - 1].params.sleep_gap != 0)
			usleep(saved_monitor->philos[philo_number - 1].params.sleep_gap);
	}
	if (is_dinner_finished(philo_number))
		return ;
}

void	put_forks(unsigned int philo_number)
{
	static t_monitor	*saved_monitor;

	get_monitor(&saved_monitor);
	change_fork_state(saved_monitor->philos[philo_number - 1].right_fork, false);
	change_fork_state(saved_monitor->philos[philo_number - 1].left_fork, false);
	if (is_dinner_finished(philo_number))
		return ;
}

void	delay_even_philos(t_philo *philo)
{
	if (philo->number % 2 == 0)
	{
		usleep((philo->params.time_to_die / 2) * 1000);
	}
}

int	is_state_finish(t_philo *philo)
{
	t_state				state;

	state = get_current_philo_state(philo->number);
	if (state == FINISH || state == FULL)
		return (true);
	return (false);
}

int	routine_process(t_philo *philo)
{
	static t_monitor	*saved_monitor;

	get_monitor(&saved_monitor);
	take_fork(philo->number);
	if (is_state_finish(philo))
		return (FAIL);
	eat(philo->number);
	if (is_state_finish(philo))
		return (FAIL);
	put_forks(philo->number);
	check_meal(philo->number);
	if (is_state_finish(philo))
		return (FAIL);
	psleep(philo->number);
	if (is_state_finish(philo))
		return (FAIL);
	think(philo->number);
	if (is_state_finish(philo))
		return (FAIL);
	return (OK);
}

void	*routine(void *arg)
{
	static t_monitor	*saved_monitor;
	t_philo				*philo;

	get_monitor(&saved_monitor);
	philo = (t_philo *)arg;
	wait_until_start_eating();
	philo->last_meal = get_current_time();
	print_state(philo->number);
	delay_even_philos(philo);
	while (true)
	{
		if (routine_process(philo) == FAIL)
			return (NULL);
	}
	return (NULL);
}

int	ft_create_threads(t_monitor *monitor)
{
	size_t	i;

	i = 0;
	save_monitor(monitor);
	while (i < monitor->philos->params.number_of_philosophers)
	{
		if (pthread_create(&(monitor->philos + i)->thread, NULL, &routine, (monitor->philos + i)) != 0)
		{
			ft_puterror("Error creating thread");
		}
		i++;
	}
	i = 0;
	pthread_mutex_lock(&(monitor->monitor_mutex));
	monitor->everyone_at_the_table = true;
	pthread_mutex_unlock(&(monitor->monitor_mutex));
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

int	ft_init_forks(t_philo *philos, t_monitor *monitor)
{
	size_t	i;

	i = 0;
	while (i < philos->params.number_of_philosophers)
	{
		(monitor->forks + i)->locked = false;
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

t_monitor	*ft_assign_monitor(t_philo *philos)
{
	t_monitor *monitor;

	monitor = ft_calloc(1, sizeof(t_monitor));
	if (monitor == NULL)
		return (NULL);
	monitor->philos = philos;
	pthread_mutex_init(&monitor->print_state_mutex, NULL);
	pthread_mutex_init(&monitor->monitor_mutex, NULL);
	monitor->forks = ft_calloc(philos->params.number_of_philosophers, sizeof(t_fork));
	if (monitor->forks == NULL)
	{
		pthread_mutex_destroy(&monitor->print_state_mutex);
		pthread_mutex_destroy(&monitor->monitor_mutex);
		free(monitor);
		return (NULL);
	}
	if (ft_init_forks(philos, monitor) == FAIL)
	{
		pthread_mutex_destroy(&monitor->print_state_mutex);
		pthread_mutex_destroy(&monitor->monitor_mutex);
		free(monitor);
		return (NULL);
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
		return (EXIT_FAILURE);
	monitor = ft_assign_monitor(philos);
	if (monitor == NULL)
		return (ft_cleanup_philos(philos), EXIT_FAILURE);
	ft_create_threads(monitor);
	ft_cleanup_monitor(monitor);
}
