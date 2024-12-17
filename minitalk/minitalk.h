/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:22:07 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/17 21:18:23 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

void	ft_puterror(char *msg);
void	ft_create_signal(int signum, void *act_handler, bool use_siginfo);
void	send_signal(pid_t pid, int signum);

#endif