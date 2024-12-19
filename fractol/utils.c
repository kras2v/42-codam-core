/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:12:14 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/19 19:00:06 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double scale_pixel_to_coord(int pix, int size, double min, double max)
{
	return (min + (pix / (double)size) * (max - min));
}

void	my_put_pixel(t_img_data *img, int x, int y, int color)
{
	int	offset;
	
	offset = y * img->size_line + x * (img->bites_per_pixel / 8);
	*((unsigned int*)(offset + img->data_addr)) = color;
}
