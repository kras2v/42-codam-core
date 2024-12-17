/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:49:53 by valeriia          #+#    #+#             */
/*   Updated: 2024/12/17 21:45:11 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile int	g_lock = true;

static void	change_status(int signum)
{
	if (signum == SIGUSR1)
		g_lock = false;
}

static void	show_message_status(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_printf("Message received\n");
		exit(EXIT_SUCCESS);
	}
}

static void	encrypt_signal(pid_t server_pid, char letter)
{
	int		mask;
	size_t	i;

	(void)server_pid;
	mask = 0b10000000;
	i = 0;
	while (i < CHAR_BIT)
	{
		if (letter & (mask >> i))
			send_signal(server_pid, SIGUSR1);
		else
			send_signal(server_pid, SIGUSR2);
		i++;
		while (g_lock)
			usleep(50);
		g_lock = true;
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	char				*msg_to_send;
	size_t				i;

	if (argc != 3)
		ft_puterror("Not enough arguments.");
	ft_printf("__PID: %d", getpid());
	ft_create_signal(SIGUSR1, change_status, false);
	ft_create_signal(SIGUSR2, show_message_status, false);
	server_pid = ft_atoi(argv[1]);
	msg_to_send = argv[2];
	i = 0;
	while (msg_to_send[i] != '\0')
	{
		encrypt_signal(server_pid, msg_to_send[i]);
		i++;
	}
	encrypt_signal(server_pid, '\0');
	exit(EXIT_SUCCESS);
}
