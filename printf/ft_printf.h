/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:04:10 by valeriia          #+#    #+#             */
/*   Updated: 2024/10/19 17:37:56 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h" 
# include "stdarg.h"

void	ft_printf_c(char a);
void	ft_printf_s(char *a);
void	ft_printf_d(int num);
int		ft_printf(const char * format, ...);

#endif