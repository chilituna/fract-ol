/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:04:02 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/28 20:00:59 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	f;

	ft_check_input(argc, argv);
	ft_create_fractal(argv, &f);
	mlx_image_to_window(f.mlx, f.image, 0, 0);
	mlx_key_hook(f.mlx, &ft_key_events, &f);
	mlx_mouse_hook(f.mlx, ft_m, &f);
	mlx_scroll_hook(f.mlx, &ft_scroll_events, &f);
	mlx_close_hook(f.mlx, ft_end_program, &f);
	mlx_image_to_window(f.mlx, f.image, 0, 0);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (0);
}
