/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:57:47 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/16 23:26:14 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

char	*convert_to_binary(char *res, int num)
{
	int	mask;
	int	i;

	mask = 0b10000000;
	i = 0;
	while (i < 8)
	{
		if (mask & num)
			res[i] = '1';
		else
			res[i] = '0';
		mask >>= 1;
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	send_signal(pid_t PID, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
		{
			if (kill(PID, SIGUSR1) == -1)
				exit(1);
			usleep(200);
		}
		else if (str[i] == '1')
		{
			if (kill(PID, SIGUSR2) == -1)
				exit(1);
			usleep(200);
		}
		i++;
	}
}

void	encrypt(pid_t PID, char *string)
{
	size_t	i;
	char	*binary;

	i = 0;
	binary = malloc(9);
	if (!binary)
		exit(1);
	while (string[i] != '\0')
	{
		binary = convert_to_binary(binary, string[i]);
		send_signal(PID, binary);
		i++;
	}
	free(binary);
	binary = NULL;
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
		{
			return (-1);
		}
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
	printf("__PID: %d\n", getpid());
	encrypt(get_pid(argv[1]), argv[2]);
	return (0);
}