/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:04:07 by valeriia          #+#    #+#             */
/*   Updated: 2024/10/22 11:58:24 by kvalerii         ###   ########.fr       */
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

static int ft_choose_string_convension(va_list list, const char *format)
{
	if (*format == 'c')
	{
		return ft_printf_c(va_arg(list, int));
	}
	else if(*format == 's')
	{
		return ft_printf_s(va_arg(list, char *));
	}
	else if(*format == '%')
	{
		return ft_printf_percent('%');
	}
	return (0);
}

static int ft_choose_int_convension(va_list list, const char *format)
{
	if(*format == 'd')
	{
		return ft_printf_d(va_arg(list, int));
	}
	else if(*format == 'i')
	{
		return ft_printf_i(va_arg(list, int));
	}
	return (0);
}

static int ft_choose_hex_convension(va_list list, const char *format)
{
	if(*format == 'p')
	{
		return ft_printf_p(va_arg(list, unsigned long));
	}
	else if(*format == 'u')
	{
		return ft_printf_u(va_arg(list, unsigned int));
	}
	else if(*format == 'x')
	{
		return ft_printf_x(va_arg(list, unsigned int));
	}
	else if(*format == 'X')
	{
		return ft_printf_X(va_arg(list, unsigned int));
	}
	return (0);
}

static int ft_choose_convension(va_list list, const char *format)
{
	if (*format == 'c' 
		|| *format == 's' 
		|| *format == '%')
		return ft_choose_string_convension(list, format);
	else if (*format == 'd' 
		|| *format == 'i')
		return  ft_choose_int_convension(list, format);
	else if(*format == 'p' 
		|| *format == 'u' 
		|| *format == 'x'
		|| *format == 'X')
		return ft_choose_hex_convension(list, format);
	return (0);
}

int ft_printf(const char * format, ...)
{
	va_list	list;
	int		len;

	len = 0;
	va_start(list, format);
	while (*format)
	{
		if (ft_check_conv_format_and_move(&format))
		{
			if (ft_is_conversion(*format))
				len += ft_choose_convension(list, format);
		}
		else
			len += ft_printf_c(*format);
		format++;
	}
	va_end(list);
	return (len);
}

/* #include <stdio.h>
int main(void)
{
	// ft_printf("ft_printf c - %c\n", 'c');
	// printf("printf c - %c\n", 'c');

	// ft_printf("ft_printf s- %s\n", "fsafsaf");
	// printf("printf s- %s\n", "fsafsaf");

	// ft_printf("ft_printf p - %p\n", NULL);
	// printf("printf p - %p\n", NULL);

	// ft_printf("ft_printf d- %d\n", 10000000);
	// printf("printf d- %d\n", 10000000);

	// ft_printf("ft_printf i - %i\n", -1000000);
	// printf("printf i - %i\n", -1000000);

	// ft_printf("ft_printf u - %u\n", 10000000);
	// printf("printf u - %u\n", 10000000);

	ft_printf("ft_printf x - %x\n", LONG_MAX);
	//printf("printf x - %x\n", LONG_MAX);

	// ft_printf("ft_printf X - %X\n", -10);
	// printf("printf X - %X\n", -10);

	// ft_printf("ft_printf perc - %% \n");
	// printf("printf perc - %% \n");
} */