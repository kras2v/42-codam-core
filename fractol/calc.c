/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:37:06 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/21 22:22:03 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	hsv_to_rgb(double hue, double saturation, double value)
{
	int		hi;
	int		v;
	int		p;
	int		q;
	int		t;
	double	f;

	hi = (int)(hue / 60) % 6;
	value *= 255;
	f = hue / 60 - (int)(hue / 60);
	v = (int)value;
	p = (int)(value * (1 - saturation));
	q = (int)(value * (1 - f * saturation));
	t = (int)(value * (1 - (1 - f) * saturation));
	if (hi == 0)
        return create_trgb(0, v, t, p);
    else if (hi == 1)
        return create_trgb(0, q, v, p);
    else if (hi == 2)
        return create_trgb(0, p, v, t);
    else if (hi == 3)
        return create_trgb(0, p, q, v);
    else if (hi == 4)
        return create_trgb(0, t, p, v);
    else
        return create_trgb(0, v, p, q);
}

double d_abs(double abs)
{
	if (abs < 0)
		return (-abs);
	return (abs);
}

int coloring(int i, t_compex z)
{
	double	di;
	double	zn;
	double	hue;

	di = i * 2.5;
	zn = sqrt(z.imag + z.real);
	hue = di + 1.0 - log2(log(d_abs(zn)));
	hue = 5.0 * hue;
	while (hue > 360)
		hue -= 360;
	while (hue < 360)
		hue += 360;
	return hsv_to_rgb(hue, 0.9, 1.0);
}

int	calc(t_compex C, int max_iterations)
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
	if (i == max_iterations)
		return create_trgb(0, 0, 0, 0);
	return coloring(i, Z);
}
