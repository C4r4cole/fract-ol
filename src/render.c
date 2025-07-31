/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:19:28 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/31 21:24:51 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractal, t_colors colors)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = (map(x, (t_min_max){-2, +2, 0, WIDTH})
			* fractal->zoom) + fractal->shift_x;
	z.y = (map(y, (t_min_max){+2, -2, 0, HEIGHT})
			* fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	i = 0;
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, (t_min_max){colors.color1,
					colors.color2, 0, fractal->iterations_definition});
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int			x;
	int			y;
	t_colors	colors;

	colors.color1 = RED;
	colors.color2 = BLUE;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y % 2 == 0)
				handle_pixel(x, y, fractal, colors);
			else
			{
				colors.color1++;
				colors.color2++;
				handle_pixel(x, y, fractal, colors);
			}
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->img.img, 0, 0);
}
