/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:08 by fmoulin           #+#    #+#             */
/*   Updated: 2025/08/01 18:05:12 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Please enter\n\
						./fractol mandelbrot\" or\n\
						./fractol julia <value 1> <value 2>\n\
						must be of type double\n"
# define WIDTH 1080
# define HEIGHT 1080

# define BLACK	0x000000
# define RED	0xFF0000
# define BLUE	0x0000FF

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_colors
{
	int	color1;
	int	color2;
}				t_colors;

typedef struct s_min_max
{
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}				t_min_max;

void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
void		fractal_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		handle_pixel(int x, int y, t_fractal *fractal, t_colors colors);
void		malloc_error(void);
int			main(int argc, char **argv);
double		map(double unscaled_num, t_min_max min_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		events_init(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
void		mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal);

#endif