/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:04:07 by valeriia          #+#    #+#             */
/*   Updated: 2024/10/19 18:06:42 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_is_conversion(const char a)
{
	return (a == 'c'
		|| a == 's'
		|| a == 'p'
		|| a == 'd'
		|| a == 'i'
		|| a == 'u'
		|| a == 'x'
		|| a == 'X'
		|| a == '%');
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

static void ft_choose_convension(va_list list, const char *format)
{
	if (*format == 'c')
	{
		ft_printf_c(va_arg(list, int));
	}
	else if(*format == 's')
	{
		ft_printf_s(va_arg(list, char *));
	}
	else if(*format == 'd')
	{
		ft_printf_d(va_arg(list, int));
	}
	else if(*format == 'i')
	{
		ft_printf_d(va_arg(list, int));
	}
	/* else if(*format == 'p')
	{
		ft_printf_p();
	}
	else if(*format == 'u')
	{
		ft_printf_u();
	}
	else if(*format == 'x')
	{
		ft_printf_x();
	}
	else if(*format == 'X')
	{
		ft_printf_X();
	}
	*/
	else if(*format == '%')
	{
		ft_printf_c('%');
	} 
}

int	ft_count_args(const char * a)
{
	int		args_amount;
	
	args_amount = 0;
	while (*a != '\0')
	{
		if (ft_check_conv_format_and_move(&a))
		{
			args_amount++;
		}
		a++;
	}
	return (args_amount);
}

int ft_printf(const char * format, ...)
{
	va_list	list;
	int		args_amount;

	args_amount = ft_count_args(format);
	va_start(list, format);
	while (*format)
	{
		if (ft_check_conv_format_and_move(&format))
		{
			if (ft_is_conversion(*format))
				ft_choose_convension(list, format);
		}
		else
			ft_printf_c(*format);
		format++;
	}
	va_end(list);
	return (1);
}

/* #include <stdio.h>
int main(void)
{
	ft_printf("%c", '0');
} */