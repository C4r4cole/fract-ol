/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:19:28 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/24 14:13:48 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0;
	z.y = 0.0;
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, +2, -2, 0, HEIGHT);
	i = 0;
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_definition);
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

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img, 0, 0);
}
