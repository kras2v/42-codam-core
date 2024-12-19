/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:31:22 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/19 22:42:36 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "libft/libft.h"

#define WIDTH 1200
#define HEIGHT 1200
#define min_scale_X -2
#define max_scale_X 1
#define min_scale_Y -1.2
#define max_scale_Y min_scale_X+(max_scale_X-min_scale_Y)*HEIGHT/WIDTH

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

typedef struct s_color
{
	int t;
	int r;
	int g;
	int b;
} t_color;

int		calc(t_compex C, int max_iterations);
void	my_put_pixel(t_img_data *img, int x, int y, int color);

int generate_color(double hue);
void coloring(int max_iterations);
double scale_pixel_to_coord(int pix, int size, double min, double max);


#endif 