/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:21:14 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/30 18:04:39 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int main(void)
// {
// 	t_complex	z;
// 	t_complex	c;
// 	double		tmp_real;
// 	int			i;

// 	i = 0;
// 	z.real = 0;
// 	z.i = 0;
// 	c.real = 0.25;
// 	c.i = 0.4;

// 	// Pour faire mandelbrot, voici la fonction a resoudre
// 	// f(z) = z^2 + c
// 	// on dit que la fonction est resolue quand on la derive et que son resultat ne tend pas vers l'infini
// 	// racine carre de -1 = i donc i^2 = -1

// 	// Formule pour mettre un nombre complexe au carre :
// 	// (x + yi)^2 = (x + yi) * (x + yi)
// 	// (x + yi) * (x + yi) = x^2 + xyi + xyi + y^2i^2
// 	// x^2 + xyi + xyi + y^2i^2 = x^2 + 2xyi - y^2       (parce que i^2 = -1)
// 	// x^2 + 2xyi - y^2 = x^2 - y^2 + 2xyi
// 	while (i < 42)
// 	{
// 		tmp_real = (z.real * z.real) - (z.i * z.i);
// 		z.i = 2 * z.real * z.i;
// 		z.real = tmp_real;
// 		z.real += c.real;
// 		z.i += c.i;
// 		i++;
// 		printf("iteration %d -> real = %f / immaginary = %f\n", i, z.real, z.i);
// 	}
// }

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
		{
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
