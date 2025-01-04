/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_coloring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:34:51 by valeriia          #+#    #+#             */
/*   Updated: 2025/01/04 18:18:44 by kvalerii         ###   ########.fr       */
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

t_color get_color(int r, int g, int b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
