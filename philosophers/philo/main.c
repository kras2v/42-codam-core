/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:18:25 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/07 12:40:47 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
