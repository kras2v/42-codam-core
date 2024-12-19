/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:31:22 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/19 18:11:21 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "libft/libft.h"

#define WIDTH 1500
#define HEIGHT 1500
#define min_scale_X -2
#define max_scale_X 0.47
#define min_scale_Y -1.12
#define max_scale_Y 1.12

typedef struct s_img_data
{
	void		*img_ptr;
	char		*data_addr;
	int			bites_per_pixel;
	int			size_line;
	int			endian;
	int			*pallete;
} t_img_data;

typedef struct s_my_display
{
	void	*mlx;
	void	*win;
	t_img_data	img_data;
}	t_my_display;

typedef struct s_compex
{
	double real;
	double imag;
} t_compex;


int		calc(t_compex C, int max_iterations);
void	my_put_pixel(t_img_data *img, float x, float y, int color);


int generate_color(double hue);
void coloring(double ***hue, int max_iterations);
double scale_pixel_to_coord(int pix, int size, double min, double max);


#endif 