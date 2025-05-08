/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:40:29 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/08 10:35:11 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_show_philo_action(unsigned int philo_number, char *msg)
{
	printf("%ld %d %s\n", ft_get_current_time(), philo_number, msg);
}

long	ft_get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	ft_print_state(unsigned int philo_number, t_monitor *saved_monitor)
{
	t_state				state;

	pthread_mutex_lock(&(saved_monitor->print_state_mutex));
	state = ft_get_current_philo_state(philo_number, saved_monitor);
	if (state == THINKING)
		ft_show_philo_action(philo_number, GREEN"is thinking"RESET);
	else if (state == EATING)
		ft_show_philo_action(philo_number, YELLOW"is eating"RESET);
	else if (state == SLEEPING)
		ft_show_philo_action(philo_number, BLUE"is sleeping"RESET);
	else if (state == DIED)
		ft_show_philo_action(philo_number, RED"died"RESET);
	else if (state == GOTFORK)
		ft_show_philo_action(philo_number, MAGENTA"has taken a fork"RESET);
	pthread_mutex_unlock(&(saved_monitor->print_state_mutex));
}
