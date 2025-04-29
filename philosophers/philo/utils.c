/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:46:53 by valeriia          #+#    #+#             */
/*   Updated: 2025/04/28 21:09:10 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_isanum(char character)
{
	return (character >= '0' && character <= '9');
}

long	ft_atol(char *str)
{
	long	result;
	int		sign;
	size_t	i;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isanum(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_calculate_num_len(int number)
{
	size_t	len;
	size_t	l_number;

	len = 0;
	l_number = number;
	if (number == 0)
	{
		return (1);
	}
	if (number < 0)
	{
		len++;
		l_number *= -1;
	}
	while (l_number > 0)
	{
		l_number /= 10;
		len++;
	}
	return (len);
}

int	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

void	ft_puterror(char *msg)
{
	write(2, msg, ft_strlen(msg));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	char	*p_alloc;
	size_t	i;

	alloc = malloc(nmemb * size);
	if (alloc == NULL)
	{
		ft_puterror("Error allocating memory");
		return (NULL);
	}
	i = 0;
	p_alloc = (char *)alloc;
	while (i < nmemb * size)
	{
		*p_alloc = 0;
		p_alloc++;
		i++;
	}
	return (alloc);
}

void	ft_cleanup_philos(t_philo *philos)
{
	if (philos != NULL)
	{
		free(philos);
	}
}

void	ft_cleanup_forks(t_philo_routine *routine, size_t	number_of_philosophers)
{
	size_t	i;

	if (routine->forks_mutex != NULL)
	{
		while (i < number_of_philosophers)
		{
			pthread_mutex_destroy((routine->forks_mutex + i));
			i++;
		}
		free(routine->forks_mutex);
	}
	if (routine->forks != NULL)
	{
		free(routine->forks);
	}
}

void	ft_cleanup_routine(t_philo_routine *routine)
{
	ft_cleanup_forks(routine, routine->philos->params.number_of_philosophers);
	ft_cleanup_philos(routine->philos);
	pthread_mutex_destroy(&routine->portions_eaten_mutex);
	pthread_mutex_destroy(&routine->print_state_mutex);
}
