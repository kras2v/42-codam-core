/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:50:48 by valeriia          #+#    #+#             */
/*   Updated: 2024/12/17 21:05:26 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_puterror(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	ft_create_signal(int signum, void *act_handler, bool use_siginfo)
{
	struct sigaction	action;

	if (use_siginfo)
	{
		action.sa_flags = SA_SIGINFO;
		action.sa_sigaction = act_handler;
	}
	else
	{
		action.sa_flags = 0;
		action.sa_handler = act_handler;
	}
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(signum, &action, NULL);
}

void	send_signal(pid_t pid, int signum)
{
	if (kill(pid, signum) == -1)
	{
		ft_puterror("Error sending a signal");
	}
}
