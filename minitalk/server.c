/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:19:40 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/16 23:30:42 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <time.h>

size_t	_pow(size_t num, int pow)
{
	if (pow == 0)
		return (1);
	return (num * _pow(num, pow - 1));
}

char	binary_to_char(char *num)
{
	int		dec;
	char	letter;
	size_t	i;
	size_t	len;

	dec = 0;
	i = 0;
	len = ft_strlen(num);
	while(num[i] != '\0')
	{
		dec += (int)((num[i] - '0') * _pow(2, len - i - 1));
		i++;
	}
	letter = dec;
	return (letter);
}

void	signal_handler(int signum)
{
	static int num = 0;
	static char *res = NULL;
	char letter;

	if(!res)
	{
		res = malloc(9 * sizeof(char));
		if (!res)
			exit(1);
	}
	if (signum == SIGUSR1)
	{
		res[num] = '0';
		num++;
	}
	else if (signum == SIGUSR2)
	{
		res[num] = '1';
		num++;
	}
	if (num == 8)
	{
		res[num] = '\0';
		letter = binary_to_char(res);
		num = 0;
		write(1, &letter, 1);
		free(res);
		res = NULL;
	}
}

void exit_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "Exiting...\n", 11);
		exit(0);
	}
}

int main()
{
	ft_printf("%d\n", getpid());
	struct sigaction action;
	action.sa_handler = signal_handler;
	action.sa_flags = 0;
	sigfillset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	signal(SIGINT, exit_handler);
	while (1)
	{
		
	}
}