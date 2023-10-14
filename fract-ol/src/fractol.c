/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:04:02 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/13 19:46:38 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_end_program(t_fractal *fractal, mlx_image_t *image)
{
	mlx_delete_image(fractal->mlx_connection, image);
	mlx_close_window(fractal->mlx_connection);
	mlx_terminate(fractal->mlx_connection);
	free(fractal);
	exit(EXIT_SUCCESS);
}

int32_t	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 6)))
		fractal = (t_fractal *)malloc(sizeof(t_fractal));
	else
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_create_fractal(fractal, argv[1]);
	mlx_key_hook(fractal->mlx_connection, ft_key_events, fractal);
	mlx_loop(fractal->mlx_connection);
}
