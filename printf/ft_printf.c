/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:04:07 by valeriia          #+#    #+#             */
/*   Updated: 2024/10/19 16:38:52 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_is_conversion(const char *a)
{
	return (*a == 'c'
		|| *a == 's'
		|| *a == 'p'
		|| *a == 'd'
		|| *a == 'i'
		|| *a == 'u'
		|| *a == 'x'
		|| *a == 'X'
		|| *a == '%');
}

int	ft_check_conv_format_and_move(const char **a)
{
	if (**a == '%')
	{
		(*a)++;
		return (1);
	}
	return (0);
}

static int ft_choose_convension(const char *a, void *arg)
{
	if (*a == 'c')
	{
		ft_printf_c((char)arg);
	}
	else if(*a == 's')
	{
		ft_printf_s((char *)arg);
	}
	else if(*a == 'p')
	{
		ft_printf_p();
	}
	else if(*a == 'd')
	{
		ft_printf_d();
	}
	else if(*a == 'i')
	{
		ft_printf_i();
	}
	else if(*a == 'u')
	{
		ft_printf_u();
	}
	else if(*a == 'x')
	{
		ft_printf_x();
	}
	else if(*a == 'X')
	{
		ft_printf_X();
	}
	else if(*a == '%')
	{
		ft_printf_percent();
}
}

int	ft_count_args(const char * a)
{
	int		args_amount;
	void	*arg;
	
	args_amount = 0;
	while (*a != '\0')
	{
		if (ft_check_conv_format_and_move(&a))
		{
			ft_choose_convension();
		}
		a++;
	}
	return (args_amount);
}

int ft_printf(const char * a, ...)
{
	va_list	list;
	int		args_amount;
	int		i;

	args_amount = ft_count_args(a);
	va_start(list, args_amount);
	i = 0;
	while (a[i] != '\0')
	{
		if (ft_check_conv_format_and_move(&a))
		{
			
		}
		i++;
	}
	ft_putstr_fd((char *)a, 0);
	va_end(list);
	return (1);
}

#include <stdio.h>
int main(void)
{
	ft_printf("%s", "fasfa", 531531);
}