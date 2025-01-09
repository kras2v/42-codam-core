/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:31:22 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/09 23:05:30 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// Screen parameters
enum
{
	WIDTH = 800,
	HEIGHT = 800
};

// Events
enum
{
	ON_DESTROY = 17,
	ON_MOUSEMOVE = 6,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
	LEFT_CLICK = 1
};

typedef struct s_scale
{
	double	min_real;
	double	max_real;
	double	min_imag;
	double	max_imag;
}	t_scale;

typedef struct s_img_size
{
	int	min_px;
	int	max_px;
	int	min_py;
	int	max_py;
}	t_img_size;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractol
{
	t_scale		scale;
	char		name;
	char		color_type;
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
}	t_img_data;

typedef struct s_my_display
{
	void		*mlx;
	void		*win;
	t_img_data	img_data;
}	t_my_display;

typedef struct s_pixels
{
	int	px;
	int	py;
}	t_pixels;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_double
{
	char	*before_dot;
	char	*after_dot;
	int		is_negative;
	int		num_before_dot;
	int		num_after_dot;
	int		dots;
}	t_double;

double			ft_fractal_atof(char *argv, t_my_display *my_display);

// Complex number calculations
t_complex		c_cube(t_complex z);
t_complex		c_square(t_complex z);
t_complex		division(t_complex dividend, t_complex divisor);
t_complex		subtraction(t_complex minuend, t_complex subtrahend);

// Fractals implementation
int				calculate_mandelbrot(t_fractol *mandelbrot);
int				calculate_julia(t_complex Z, t_fractol *julia);
int				calculate_newton(t_fractol newton, t_color change);

// Fractal rendering on a image
void			render_mandelbrot(t_img_data *img_data);
void			render_julia(t_img_data *img_data);
void			render_newton(t_img_data *img_data, int do_change);

// Fractal initialization
void			initialize_mandelbrot(t_my_display *my_display,
					int max_iterations);
void			initialize_newton(t_my_display *my_display,
					int max_iterations);
void			initialize_julia(t_complex c, t_my_display *my_display,
					int max_iterations);

// Color managment
int				create_rgb(int r, int g, int b);
int				hsv_to_rgb(double hue, double saturation, double value);
t_color			get_color(int r, int g, int b);
int				rainbow_coloring(int i, t_complex z, char name);
int				standart_coloring(int i, int max_iterations);
int				newton_coloring(int root, t_color change);

//Events
void			identify_event_handlers(t_my_display *my_display);
int				key_up_events(int keysym, t_my_display *my_display);
int				mouse_scroll_events(int button, int px,
					int py, t_my_display *my_display);
int				change_julia(int px, int py, t_my_display *my_display);
void			change_scale_parametrs(t_scale *old, t_scale new);
void			zoom(int btn, int x, int y, t_my_display *my_display);
void			execute_fractal_rendering(t_img_data *img_data,
					int change_color);

void			my_put_pixel(t_img_data *img, int x, int y, int color);
void			init_img_size(t_img_size *img_size, t_pixels min, t_pixels max);
void			create_img_data(t_my_display *my_display);
t_my_display	create_my_display(void);

void			display_info(void);
void			send_error_msg(char *msg);
void			free_and_exit(t_my_display *my_display,
					int exit_code, char *msg);
t_scale			create_scale(double max_imag, double min_imag,
					double max_real, double min_real);

double			convert_pixel_to_coordinate(int pix,
					t_img_data *img_data, t_fractol *fractol, char direction);

#endif 