/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:26:39 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/28 20:39:11 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//zooming in and out the center of the fractal
void	ft_zoom(t_fractal *f, double i)
{
	double	width;
	double	height;
	double	new_width;
	double	new_height;

	width = f->max.real - f->min.real;
	height = f->max.imag - f->min.imag;
	new_width = (f->max.real - f->min.real) / i;
	new_height = (f->max.imag - f->min.imag) / i;
	f->min.real -= (new_width - width) / 2;
	f->max.real = f->min.real + new_width;
	f->min.imag -= (new_height - height) / 2;
	f->max.imag = f->min.imag + new_height;
	ft_fractal_prep(f);
}

//move the fractal
void	ft_move(t_fractal *f, double x, double y)
{
	double	x_width;
	double	y_height;
	double	move_x;
	double	move_y;	

	x_width = f->max.real - f->min.real;
	y_height = f->max.imag - f->min.imag; 
	move_x = x * x_width;
	move_y = y * y_height;
	f->min.real += move_x;
	f->max.real += move_x;
	f->min.imag += move_y;
	f->max.imag += move_y;
	ft_fractal_prep(f);
}

//move the fractal to match mouse cursor pixel
//scale the current mouse cursor pixel to the fractal values
//calculate the difference between the current value and the goal value
//calculate the percentage to give to ft_move
void	ft_move_mouse(t_fractal *f, double x_value, double y_value)
{
	double	x;
	double	y;
	double	move_x;
	double	move_y;

	x = ((double)f->mouse.real / WIDTH) 
		* (f->max.real - f->min.real) + f->min.real;
	y = f->max.imag - ((double)f->mouse.imag / HEIGHT) 
		* (f->max.imag - f->min.imag);
	move_x = (x - x_value) / (f->max.real - f->min.real);
	move_y = (y - y_value) / (f->max.imag - f->min.imag);
	ft_move(f, -move_x, move_y);
}

//updating the value to zoom in the middle of the fractal
void	ft_zoom_mouse(t_fractal *f, double i)
{
	double	width;
	double	height;
	double	new_width;
	double	new_height;

	width = f->max.real - f->min.real;
	height = f->max.imag - f->min.imag;
	new_width = (f->max.real - f->min.real) / i;
	new_height = (f->max.imag - f->min.imag) / i;
	f->min.real -= (new_width - width) / 2;
	f->max.real = f->min.real + new_width;
	f->min.imag -= (new_height - height) / 2;
	f->max.imag = f->min.imag + new_height;
}

//zooming in and out the mouse cursor:
//first, get the mouse cursor pixel position
//then, calculate the real and imaginary values of the pixel
//then, zoom in or out
//finally, move the fractal to match the original position
void	ft_mouse_zoom(t_fractal *f, double i)
{
	int32_t	x;
	int32_t	y;
	double	x_value;
	double	y_value;

	mlx_get_mouse_pos(f->mlx, &x, &y);
	f->mouse.real = x;
	f->mouse.imag = y;
	x_value = ((double)x / WIDTH) * (f->max.real - f->min.real) + f->min.real;
	y_value = f->max.imag - ((double)y / HEIGHT) * (f->max.imag - f->min.imag);
	ft_zoom_mouse(f, i);
	ft_move_mouse(f, x_value, y_value);
}
