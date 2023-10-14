/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:04:09 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/13 19:57:18 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_malloc_error(void)
{
	perror("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

//initialize the fractal
void	ft_initialize_fractal(t_fractal *fractal)
{
	fractal->min_real = -2.0;
	fractal->max_real = 2.0;
	fractal->min_imag = -2.0;
	fractal->max_imag = 2.0;
}

//initalize mlx for the fractal
void	ft_create_fractal(t_fractal *fractal, char *name)
{
	fractal->mlx_connection = mlx_init(WIDTH, HEIGHT, name, true);
	if (!fractal->mlx_connection)
		ft_malloc_error();
	fractal->image = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!fractal->image)
		ft_malloc_error();
	//mlx_set_icon(fractal, mlx_texture_t* image);
	fractal->name = name;
	ft_initialize_fractal(fractal);
	ft_mandel(fractal);
	mlx_image_to_window(fractal->mlx_connection, fractal->image, 0, 0);
}
