/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:37:06 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/19 23:09:09 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void make_it_blue(t_color *color, int i, int max_iterations)
{
	if (i < max_iterations * 0.05)
	{
		color->b = (255 * i * max_iterations * 0.2) / max_iterations * 0.2;
		color->r = 0;
		color->g = 0;
	}	
	else if (i < max_iterations * 0.3)
	{
		color->g = (255 * (i - max_iterations * 15)) / max_iterations * 0.96;
		color->b = (255 - color->g);
		color->r = 0;
	}
	else
	{
		color->r = (255 * i * (max_iterations));
		color->g = 255 - color->r;
		color->b = (255 * i * (max_iterations * 0.2)) / max_iterations;
	}
}

void make_it_red(t_color *color, int i, int max_iterations)
{
	if (i < max_iterations * 0.05)
	{
		color->r = (255 * i * max_iterations * 0.2) / max_iterations * 0.1;
		color->g = 0;
		color->b = 0;
	}	
	else if (i < max_iterations * 0.3)
	{
		color->b = (255 * (i - max_iterations)) / max_iterations * 0.8;
		color->r = 255 - color->b;
		color->g = 0;
	}
	else
	{
		color->g = (255 * i * (max_iterations * 0.8));
		color->b = 255 - color->g;
		color->r = (255 * i * (max_iterations * 0.2)) / max_iterations;
	}
}


void make_it_green(t_color *color, int i, int max_iterations)
{
	if (i < max_iterations * 0.05)
	{
		color->g = (255 * i * max_iterations * 0.2) / max_iterations * 0.08;
		color->r = 0;
		color->b = 0;
	}	
	else if (i < max_iterations * 0.3)
	{
		color->b = (255 * (i - max_iterations)) / max_iterations * 0.1;
		color->g = 255 - color->g;
		color->r = 0;
	}
	else
	{
		color->r = (255 * i * (max_iterations * 0.3));
		color->b = 255 - color->r;
		color->g = (255 * i * (max_iterations * 0.2)) / max_iterations;
	}
}

int	calc(t_compex C, int max_iterations)
{
	t_compex Z = {0.0, 0.0};
	t_compex Ztemp = {0.0, 0.0};
	static t_color color = {1, 1, 1, 1};

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
	if (i == max_iterations)
		return create_trgb(0, 0, 0, 0);
	make_it_blue(&color, i, max_iterations);
	return create_trgb(color.t, color.r, color.g, color.b);
}
