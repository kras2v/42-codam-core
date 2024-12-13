/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:57:47 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/13 18:46:08 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	convert_to_binary(char *res, int num, int *index)
{
	if (num == 0)
	{
		res[(*index)++] = '0';
	}
	else if (num > 0)
	{
		convert_to_binary(res, num / 2, index);
		res[(*index)++] = num % 2 + '0';
	}
}

char	*zeros_string(void)
{
	char	*zero_string;
	size_t	i;

	zero_string = malloc(9 * sizeof(char));
	if (!zero_string)
		return (NULL);
	i = 0;
	while (i < 8)
	{
		zero_string[i] = '0';
		i++;
	}
	zero_string[8] = '\0';
	return (zero_string);
}

void	send_signal(pid_t PID, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
		{
			kill(PID, SIGUSR1);
			usleep(1);
		}
		else if (str[i] == '1')
		{
			kill(PID, SIGUSR2);
			usleep(1);
		}
		i++;
	}
}

void	encrypt(pid_t PID, char *string)
{
	size_t	i;
	int	index;
	char	*binary;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= 64)
			index = 0;
		else
			index = 1;
		binary = zeros_string();
		if (!binary)
			exit(1);
		convert_to_binary(binary, string[i], &index);
		//printf("%c - %s\n", string[i], binary);
		send_signal(PID, binary);
		free(binary);
		binary = NULL;
		i++;
	}
}

int	convert_to_number(char *argv)
{
	size_t	i;
	long	num;

	i = 0;
	num = 0;
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]))
		{
			return (-1);
		}
		num = num * 10 + (argv[i] - '0');
		if (num > INT_MAX)
			return (-1);
		i++;
	}
	return (num);
}

pid_t	get_pid(char *argv)
{
	pid_t	pid;

	pid = convert_to_number(argv);
	if (pid < 0)
		exit(1);
	return (pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		exit(EXIT_FAILURE);
	encrypt(get_pid(argv[1]), argv[2]);
	return (0);
}