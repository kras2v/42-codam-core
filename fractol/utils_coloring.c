/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_coloring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:34:51 by valeriia          #+#    #+#             */
/*   Updated: 2025/01/03 22:51:04 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	hsv_to_rgb(double hue, double saturation, double value)
{
	int		v;
	int		p;
	int		q;
	int		t;
	double	f;

	value *= 255;
	f = hue / 60 - (int)(hue / 60);
	v = (int)value;
	p = (int)(value * (1 - saturation));
	q = (int)(value * (1 - f * saturation));
	t = (int)(value * (1 - (1 - f) * saturation));
	if ((int)(hue / 60) % 6 == 0)
		return (create_rgb(v, t, p));
	else if ((int)(hue / 60) % 6 == 1)
		return (create_rgb(q, v, p));
	else if ((int)(hue / 60) % 6 == 2)
		return (create_rgb(p, v, t));
	else if ((int)(hue / 60) % 6 == 3)
		return (create_rgb(p, q, v));
	else if ((int)(hue / 60) % 6 == 4)
		return (create_rgb(t, p, v));
	else
		return (create_rgb(v, p, q));
}

// int coloring_m(int i, t_complex z)
// {
// 	double	di;
// 	double	zn;
// 	double	hue;

// 	di = i * 2.5;
// 	zn = sqrt(z.imag + z.real);
// 	hue = di + 1.0 - log(log(fabs(zn)));
// 	hue = 5.0 * hue;
// 	while (hue > 360)
// 		hue -= 360;
// 	while (hue < 360)
// 		hue += 360;
// 	return hsv_to_rgb(hue, 0.8, 0.9);
// }

int	coloring_m(int i, int max_iterations)
{
	t_color	color;
	double	t;

	color.r = (int)(9.0 * (1 - t) * pow(t, 3) * 255);
	color.g = (int)(15.0 * pow(1 - t, 2) * pow(t, 2) * 255);
	color.b = (int)(8.5 * pow(1 - t, 3) * t * 255);
	return (create_rgb(color.r, color.g, color.b));
}

int	coloring_j(int i, t_complex z)
{
	double	zn;
	double	hue;

	zn = z.imag * z.imag + z.real * z.real;
	hue = ((i - log(log(fabs(zn)))) * 1.5);
	return (hsv_to_rgb(hue, 0.5, 0.8));
}
