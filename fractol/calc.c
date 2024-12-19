/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:37:06 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/19 17:01:14 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int calc(t_compex C, int max_iterations)
{
	t_compex Z = {0.0, 0.0};
	t_compex Ztemp = {0.0, 0.0};

	int i = 0;
	while (i < max_iterations)
	{
		Ztemp.imag = 2 * Ztemp.imag * Ztemp.real + C.imag;
		Ztemp.real = Z.real - Z.imag + C.real;
		Z.real = Ztemp.real * Ztemp.real;
		Z.imag = Ztemp.imag * Ztemp.imag;
		if ((Z.real + Z.imag) >= 4.0)
			break;
		i++;
	}
	return (i);
}
