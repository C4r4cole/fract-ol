/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:19:28 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/31 13:05:17 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
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

void	handle_pixel(int x, int y, t_fractal *fractal, int color1, int color2)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	i = 0;
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, color1, color2, 0, fractal->iterations_definition);
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int x;
	int y;
	int	color1;
	int	color2;

	color1 = RED;
	color2 = BLUE;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y % 2 == 0)
				handle_pixel(x, y, fractal, color1, color2);
			else
				handle_pixel(x, y, fractal, ++color1, ++color2);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img, 0, 0);
}
