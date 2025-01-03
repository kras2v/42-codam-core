/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:05:15 by valeriia          #+#    #+#             */
/*   Updated: 2025/01/03 23:05:02 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_scale(int min, int max, double min_scale, double max_scale)
{
	return ((max_scale - min_scale) / (double)(max - min));
}

double	convert_pixel_to_coordinate(int pix, t_img_data *img_data,
									t_fractol *fractol, char direction)
{
	t_complex	scale;
	t_complex	scale_factor;

	if (direction == 'x')
	{
		scale.real = get_scale(img_data->size.min_px,
				img_data->size.max_px,
				fractol->scale.min_real,
				fractol->scale.max_real);
		scale_factor.real = (double)
			(fractol->scale.min_real - img_data->size.min_px * scale.real);
		return (pix * scale.real + scale_factor.real);
	}
	else if (direction == 'y')
	{
		scale.imag = get_scale(img_data->size.min_py,
				img_data->size.max_py,
				fractol->scale.min_imag,
				fractol->scale.max_imag);
		scale_factor.imag = (double)
			(fractol->scale.min_imag - img_data->size.min_py * scale.imag);
		return (pix * scale.imag + scale_factor.imag);
	}
	return (0.0);
}
