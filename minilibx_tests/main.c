#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 500

typedef struct s_data
{
	void	*img;
	char	*img_address;
	int		bites_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct s_mlx_win
{
	void	*mlx;
	void	*win;
	t_data	*img;
}	t_mlx_win;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	create_a_window(t_mlx_win *mlx_win, char *win_name)
{
	(*mlx_win).win = mlx_new_window((*mlx_win).mlx, WIDTH, HEIGHT, win_name);
}

void	my_put_pixel(t_mlx_win *mlx_win, t_point a, int color)
{
	char *offset;

	offset = a.y * mlx_win->img->line_length + a.x * (mlx_win->img->bites_per_pixel / 8);
	*((unsigned int*)(offset + *(mlx_win->img->img_address))) = color;
}

void	pallock(t_mlx_win mlx_win)
{
	int y = HEIGHT * 0.1;
	while (y < HEIGHT * 0.9)
	{
		int x = WIDTH * 0.1;
		while (x < WIDTH * 0.9)
		{
			mlx_pixel_put(mlx_win.mlx, mlx_win.win, x, y, rand() % 0x10000000);
			x++;
		}
		y++;
	}
	mlx_string_put(mlx_win.mlx, mlx_win.win, WIDTH * 0.90, HEIGHT * 0.95, rand() % 0x10000000, "palloc");
}

void	square(t_mlx_win mlx_win)
{
	int cx = WIDTH / 2;
	int cy = HEIGHT / 2;

	int xMAX = cx + 200;
	int yMAX = cy + 200;

	int	y = cy - 200;
	while (y < yMAX)
	{
		int	x = cx - 200;
		while (x < xMAX)
		{
			if ((x == 0 || x == xMAX) || (y == 0 || y == yMAX))

			y++;
		}
		x++;
	}
}

int main()
{
	t_mlx_win mlx_win;

	srand(time(NULL));
	mlx_win.mlx = mlx_init();
	create_a_window(&mlx_win, "Pallock");
	mlx_win.img->img_address = mlx_get_data_addr(mlx_win.img, &mlx_win.img->bites_per_pixel, 
			&mlx_win.img->line_length, &mlx_win.img->endian);
	pallock(mlx_win);
	mlx_clear_window(mlx_win.mlx, mlx_win.win);
	mlx_loop(mlx_win.mlx);
	return (0);
}