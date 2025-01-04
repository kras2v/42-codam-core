/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:17:31 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/04 18:26:49 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rainbow_coloring(int i, t_complex z, char name)
{
	double	zn;
	double	hue;
	double	saturation;
	double	value;

	hue = 0.0;
	saturation = 0.0;
	value = 0.0;
	if (name == 'M')
	{
		zn = sqrt(z.imag + z.real);
		hue = 5.0 * (i - log(log(fabs(zn))) * 1.5);
		saturation = 0.8;
		value = 0.9;
	}
	else if (name == 'J')
	{
		zn = z.imag * z.imag + z.real * z.real;
		hue = 2.0 * ((i - log(log(fabs(zn)))) * 1.5);
		saturation = 0.8;
		value = 0.9;
	}
	return (hsv_to_rgb(hue, saturation, value));
}

int	standart_coloring(int i, int max_iterations)
{
	t_color	color;
	double	t;

	t = ((double)i / (double)max_iterations);
	color.r = (int)(9.0 * (1 - t) * pow(t, 3) * 255);
	color.g = (int)(15.0 * pow(1 - t, 2) * pow(t, 2) * 255);
	color.b = (int)(8.5 * pow(1 - t, 3) * t * 255);
	return (create_rgb(color.r, color.g, color.b));
}

int newton_coloring(int root, t_color change)
{
	t_color colors[4];

	colors[0] = get_color(0, 0, 150);
	colors[1] = get_color(150, 0, 0);
	colors[2] = get_color(0, 150, 0);
	colors[3] = get_color(0, 0, 150);
	return create_rgb(colors[root].r + change.r, colors[root].g + change.g, colors[root].b + change.b);
}