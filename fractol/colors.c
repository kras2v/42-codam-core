#include "fractol.h"
#include <string.h>

void coloring(double ***hue, int max_iterations)
{
	int px = 0;
	int py = 0;
	int curr_iterations = 0;
	int iteration_counts[WIDTH][HEIGHT];
	int num_iterations_per_pixel[max_iterations];

	double minX = -2;
	double maxX = 0.47;
	double minY = -1.12;
	double maxY = 1.12;
	
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			(*hue)[x][y] = 0.0;
		}
	}
	memset(iteration_counts, 0, sizeof(iteration_counts));
	memset(num_iterations_per_pixel, 0, sizeof(num_iterations_per_pixel));
	while (py < HEIGHT)
	{
		px = 0;
		double y = scale_pixel_to_coord(py, HEIGHT, minY, maxY);
		while (px < WIDTH)
		{
			double x = scale_pixel_to_coord(px, WIDTH, minX, maxX);
			t_compex c = {x, y};
			curr_iterations = calc(c, max_iterations);
			iteration_counts[px][py] = curr_iterations;
			num_iterations_per_pixel[curr_iterations]++;
			px++;
		}
		py++;
	}
	int i = 0;
	int total = 0;
	while (i < max_iterations)
	{
		total += num_iterations_per_pixel[i];
		i++;
	}
	if (total == 0) total = 1;
	py = 0;
	while (py < HEIGHT)
	{
		px = 0;
		while (px < WIDTH)
		{
			int iterations = iteration_counts[px][py];
			(*hue)[px][py] += ((double)num_iterations_per_pixel[iterations] / (double)total);
			px++;
		}
		py++;
	}
}

int generate_color(double hue) {
    int r = (int)(9 * (1 - hue) * hue * hue * hue * 255);
    int g = (int)(15 * (1 - hue) * (1 - hue) * hue * hue * 255);
    int b = (int)(8.5 * (1 - hue) * (1 - hue) * (1 - hue) * hue * 255);
    return (r << 16) | (g << 8) | b;
}
