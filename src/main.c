/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:21:14 by fmoulin           #+#    #+#             */
/*   Updated: 2025/08/01 17:10:14 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			if (!ft_strrchr(argv[3], '.') || !ft_strrchr(argv[2], '.'))
			{
				ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
			fractal.julia_y = (ft_atodbl(argv[3]));
			fractal.julia_x = (ft_atodbl(argv[2]));
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
