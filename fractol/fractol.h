/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:31:22 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/26 21:19:32 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <X11/keysym.h>
#include "libft/libft.h"

enum {
	WIDTH = 300,
	HEIGHT = 300
};

#define ON_DESTROY 17
#define ON_MOUSEMOVE 6
#define SCROLL_UP 4
#define SCROLL_DOWN 5
#define LEFT_CLICK 1

typedef struct s_scale
{
	double min_scale_X;
	double max_scale_X;
	double min_scale_Y;
	double max_scale_Y;
} t_scale;

typedef struct s_img_size
{
	int min_px;
	int max_px;
	int min_py;
	int max_py;
} t_img_size;

typedef struct s_complex
{
	double	real;
	double	imag;
} t_complex;

typedef struct s_fractol
{
	t_scale		scale;
	char		name;
	int			max_iterations;
	t_complex	c;
}	t_fractol;

typedef struct s_img_data
{
	void		*img_ptr;
	char		*data_addr;
	int			bites_per_pixel;
	int			size_line;
	int			endian;
	t_img_size	size;
	t_fractol	fractol;
} t_img_data;

typedef struct s_my_display
{
	void		*mlx;
	void		*win;
	t_img_data	img_data;

	int mouse_moved;
	int last_mouse_x;
	int last_mouse_y;
}	t_my_display;

typedef struct s_pixels
{
	int px;
	int py;
} t_pixels;

typedef struct s_color
{
	int t;
	int r;
	int g;
	int b;
} t_color;

int		calc(t_complex C, int max_iterations);
void	my_put_pixel(t_img_data *img, int x, int y, int color);

int generate_color(double hue);

double convert_pixel_to_coordinate(int pix, t_img_data *img_data, char direction);


int	calc_j(t_complex Z, t_fractol *julia);
int	calc_m(t_fractol *mandelbrot);

void free_and_exit(t_my_display *my_display, int exit_code);
t_my_display create_my_display(unsigned int max_iterations);
void	identify_event_handlers(t_my_display *my_display);

void julia(t_img_data *img_data);
void mandelbrot(t_img_data *img_data);

double ft_atof(char *argv, t_my_display *my_display);

#endif 