/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:13:23 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/28 21:44:17 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//defining key press options:
//press escape to exit
//press + to zoom in
//press - to zoom out
//press arrow keys to move the fractal
//press space to change color
void	ft_key_events(struct mlx_key_data key_data, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		ft_end_program(f);
	else if (key_data.key == MLX_KEY_BACKSPACE && key_data.action == MLX_PRESS)
		ft_zoom(f, 0.9);
	else if (key_data.key == MLX_KEY_ENTER && key_data.action == MLX_PRESS)
		ft_zoom(f, 1.1);
	else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
		ft_move(f, -0.1, 0);
	else if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
		ft_move(f, 0.1, 0);
	else if (key_data.key == MLX_KEY_UP && key_data.action == MLX_PRESS)
		ft_move(f, 0, -0.1);
	else if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS)
		ft_move(f, 0, 0.1);
	else if (key_data.key == MLX_KEY_SPACE && key_data.action == MLX_PRESS)
		ft_change_color(f);
}

//defining mouse events:
//mouse wheel zooms in and out
//zoom is centered on the mouse cursor
void	ft_scroll_events(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;

	(void) xdelta;
	f = (t_fractal *)param;
	if (ydelta > 0)
		ft_mouse_zoom(f, 1.2);
	else if (ydelta < 0)
		ft_mouse_zoom(f, 0.8);
}

//mouse click events:
//print the current mouse cursor pixel values
//if the fractal is julia, set the mouse cursor pixel as the new input value
void	ft_m(enum mouse_key b, enum action a, enum modifier_key k, void *param)
{
	int32_t		x;
	int32_t		y;
	double		real;
	double		imag;
	t_fractal	*f;

	(void) k;
	f = (t_fractal *)param;
	if (b == 0 && a == MLX_PRESS)
	{
		mlx_get_mouse_pos(f->mlx, &x, &y);
		real = ((double)x / WIDTH) * (f->max.real - f->min.real) + f->min.real;
		imag = f->max.imag - ((double)y / HEIGHT) * (f->max.imag - f->min.imag);
		if (f->name[0] == 'j')
		{
			f->input.real = real;
			f->input.imag = imag;
			ft_fractal_prep(f);
		}
		ft_printf("real: %f, imaginary: %f\n", real, imag);
	}
}
