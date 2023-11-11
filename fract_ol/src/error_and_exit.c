/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:34:15 by aarponen          #+#    #+#             */
/*   Updated: 2023/11/01 12:44:38 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_end_program(void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	mlx_delete_image(f->mlx, f->image);
	mlx_delete_texture(f->icon);
	mlx_close_window(f->mlx);
	mlx_terminate(f->mlx);
	exit(EXIT_SUCCESS);
}

void	ft_malloc_error(void)
{
	perror("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

void	ft_input_error(void)
{
	ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_julia_error(void)
{
	ft_putstr_fd(ERROR_JULIA, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
