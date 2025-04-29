/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:47:09 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/28 18:47:24 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_info_message(void)
{
	printf(YELLOW"The program ./philo must take following arguments:\n"
		"number_of_philosophers\n"
		"time_to_die\n"
		"time_to_eat\n"
		"time_to_sleep\n"
		"[number_of_times_each_philosopher_must_eat]\n\n"RESET);
}

void	ft_print_philo_params(t_philo_params philo_params)
{
	printf(BLUE "\n"
		"number_of_philosophers:                        %d\n"
		"time_to_die:                                   %d\n"
		"time_to_eat:                                   %d\n"
		"time_to_sleep:                                 %d\n"
		"[number_of_times_each_philosopher_must_eat]:   %ld\n\n" RESET,
	philo_params.number_of_philosophers,
	philo_params.time_to_die,
	philo_params.time_to_eat,
	philo_params.time_to_sleep,
	philo_params.number_of_times_each_philosopher_must_eat);
}
