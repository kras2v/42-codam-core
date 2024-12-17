/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:49:51 by valeriia          #+#    #+#             */
/*   Updated: 2024/12/17 21:45:37 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	decrypt_signal(int signum, siginfo_t *siginfo, void *ucontext)
{
	int			mask;
	static char	letter;
	static int	i;

	(void)ucontext;
	mask = 0b10000000;
	if (signum == SIGUSR1)
		letter |= (mask >> i);
	else if (signum == SIGUSR2)
		letter &= ~(mask >> i);
	else
		ft_puterror("Invalid signal received.");
	i++;
	if (i == CHAR_BIT)
	{
		i = 0;
		if (letter == '\0')
		{
			send_signal(siginfo->si_pid, SIGUSR2);
			return ;
		}
		write(1, &letter, 1);
	}
	send_signal(siginfo->si_pid, SIGUSR1);
}

void	handle_exit(int sig)
{
	if (sig == SIGINT)
		exit(0);
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf("%d", server_pid);
	ft_create_signal(SIGUSR1, decrypt_signal, true);
	ft_create_signal(SIGUSR2, decrypt_signal, true);
	ft_create_signal(SIGINT, handle_exit, false);
	while (true)
	{
		pause();
	}
	exit(EXIT_SUCCESS);
}
