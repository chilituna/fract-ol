/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:03:30 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/13 20:08:01 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../Libft/libft.h"
# include "../MLX42/MLX42.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define ERROR_MSG "Options:\n./fractol mandelbrot\n./fractol julia <r> <i>\n"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractal
{
	void		*mlx_connection;
	void		*mlx_window;
	char		*name;
	mlx_image_t	*image;
	double		min_real;
	double		max_real;
	double		min_imag;
	double		max_imag;
}	t_fractal;

//fractol.c
int32_t	main(int argc, char **argv);
void	ft_end_program(t_fractal *fractal, mlx_image_t *image);

//init.c
void	ft_create_fractal(t_fractal *fractal, char *name);
void	ft_malloc_error(void);
void	ft_initialize_fractal(t_fractal *fractal);

//calc.c
void	ft_mandel(t_fractal *fractal);
int		ft_calc_pixel(double x, double y);
void    ft_zoom(t_fractal *fractal, double i, double center_x, double center_y);
void    ft_move(t_fractal *fractal, double x, double y);

//draw.c
void	ft_color_pixel(int x, int y, int color, mlx_image_t *image);

//hooks.c
void	ft_key_events(struct mlx_key_data key_data, void *param);


#endif
