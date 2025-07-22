/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:21:14 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/22 23:16:19 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	int		color1;
	int		color2;
	int		color3;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "C4r4cole");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	color1 = 0x004B0F3C;
	color2 = 0x00C1440E;
	color3 = 0x00E2B77F;
	x = 5;
	while (x < 100)
	{
		y = 5;
		while (y < 100)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color2);
			y++;
			color1++;
		}
		x++;
	}
	while (x < 200)
	{
		y = 100;
		while (y < 200)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color2);
			y++;
			color2++;
		}
		x++;
	}
	while (x < 300)
	{
		y = 200;
		while (y < 300)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1 - color2);
			else
				my_mlx_pixel_put(&img, x, y, color2);
			y++;
			color2++;
		}
		x++;
	}
	while (x < 400)
	{
		y = 300;
		while (y < 400)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color2 - color1);
			y++;
			color2++;
		}
		x++;
	}
	while (x < 500)
	{
		y = 400;
		while (y < 500)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color2 - color1);
			y++;
			color1++;
		}
		x++;
	}
	while (x < 600)
	{
		y = 500;
		while (y < 600)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1 - color2);
			else
				my_mlx_pixel_put(&img, x, y, color2);
			y++;
			color1++;
		}
		x++;
	}
	while (x < 700)
	{
		y = 600;
		while (y < 700)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color2);
			y++;
			color1++;
		}
		x++;
	}
	while (x < 800)
	{
		y = 700;
		while (y < 800)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color2);
			y++;
			color1 += x * y;
		}
		x++;
	}
	while (x < 900)
	{
		y = 800;
		while (y < 900)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color2);
			y++;
			color2 += x * y;
		}
		x++;
	}
	while (x < 1000)
	{
		y = 800;
		while (y > 700)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color2);
			y--;
			color2 += x * y;
			color1 += x * y;
		}
		x++;
	}
	while (x < 1100)
	{
		y = 700;
		while (y > 600)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color2);
			y--;
			color2 += x / y;
			color1 += x * y;
		}
		x++;
	}
	while (x < 1200)
	{
		y = 600;
		while (y > 500)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color2);
			y--;
			color2 += x * y;
			color1 += x / y;
		}
		x++;
	}
	while (x < 1300)
	{
		y = 500;
		while (y > 400)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color3);
			y--;
			color2 += x * y;
			color3 += x / y;
		}
		x++;
	}
	while (x < 1400)
	{
		y = 400;
		while (y > 300)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color3);
			y--;
			color2 += x / y;
			color3 += x * y;
		}
		x++;
	}
	while (x < 1500)
	{
		y = 300;
		while (y > 200)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color3);
			y--;
			color2 += x * y;
			color3++;
		}
		x++;
	}
	while (x < 1600)
	{
		y = 200;
		while (y > 100)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color3);
			y--;
			color2 -= color3;
			color3 -= color1;
		}
		x++;
	}
	while (x < 1700)
	{
		y = 100;
		while (y > 5)
		{
			if (y % 2 == 0)
				my_mlx_pixel_put(&img, x, y, color1);
			else
				my_mlx_pixel_put(&img, x, y, color3);
			y--;
			color2 -= color1;
			color3 -= color2;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
