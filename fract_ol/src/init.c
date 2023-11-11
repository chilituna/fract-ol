/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:04:09 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/28 20:17:07 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//initialize the fractal
void	ft_initialize_fractal(t_fractal *f, char **argv)
{
	const char	*path;

	path = "./icons/mandel.png";
	f->min.real = -2.0;
	f->max.real = 2.0;
	f->min.imag = -2.0;
	f->max.imag = 2.0;
	f->name = argv[1];
	f->icon = mlx_load_png(path);
	f->color_fractal = 1;
	if (argv[2] && argv[3])
	{
		f->input.real = ft_atod(argv[2]);
		f->input.imag = ft_atod(argv[3]);
	}
	else
	{
		f->input.real = 0.0;
		f->input.imag = 0.0;
	}
	f->mouse.real = 0.0;
	f->mouse.imag = 0.0;
}

//initalize mlx for the fractal
void	ft_create_fractal(char **argv, t_fractal *f)
{
	ft_bzero(f, sizeof(t_fractal));
	f->mlx = mlx_init(WIDTH, HEIGHT, argv[1], false);
	if (!f->mlx)
		ft_malloc_error();
	f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->image)
	{
		mlx_close_window(f->mlx);
		mlx_terminate(f->mlx);
		ft_malloc_error();
	}
	ft_initialize_fractal(f, argv);
	mlx_set_icon(f->mlx, f->icon);
	ft_fractal_prep(f);
}
