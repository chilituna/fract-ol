/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:13:23 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/13 19:58:50 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//defining key press options:
//press escape to exit
//press + to zoom in
//press - to zoom out
//press arrow keys to move the fractal
void	ft_key_events(struct mlx_key_data key_data, void *param)
{
    t_fractal	*fractal;

    fractal = (t_fractal *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		ft_end_program(fractal, fractal->image);
    else if (key_data.key == MLX_KEY_BACKSPACE && key_data.action == MLX_PRESS)
        ft_zoom(fractal, 0.9, 0, 0);
    else if (key_data.key == MLX_KEY_ENTER && key_data.action == MLX_PRESS)
        ft_zoom(fractal, 1.1, 0, 0);
    else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
        ft_move(fractal, -0.1, 0);
    else if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
        ft_move(fractal, 0.1, 0);
    else if (key_data.key == MLX_KEY_UP && key_data.action == MLX_PRESS)
        ft_move(fractal, 0, -0.1);
    else if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS)
        ft_move(fractal, 0, 0.1);
}


//reiterate through the pixels and recalculate the colors

//change color


//hook for mousepresses
