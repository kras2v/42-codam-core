/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:12:14 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/19 17:37:10 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double scale_pixel_to_coord(int pix, int size, double min, double max)
{
	return (min + (pix / (double)size) * (max - min));
}

void	my_put_pixel(t_img_data *img, float x, float y, int color)
{
	int	offset;
	int x_int = (int)round(x);
	int y_int = (int)round(y);

	offset = y_int * img->size_line + x_int * (img->bites_per_pixel / 8);
	*((unsigned int*)(offset + img->data_addr)) = color;
}
