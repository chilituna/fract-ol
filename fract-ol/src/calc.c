/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:26:39 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/13 19:59:19 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//zooming in and out the funtion
void    ft_zoom(t_fractal *fractal, double i, double center_x, double center_y)
{
	double width = fractal->max_real - fractal->min_real;
    double height = fractal->max_imag - fractal->min_imag;

    double new_width = width / i;
    double new_height = height / i;

    double half_width_change = (new_width - width) / 2;
    double half_height_change = (new_height - height) / 2;

    fractal->min_real -= half_width_change + (center_x / WIDTH) * width;
    fractal->max_real = fractal->min_real + new_width;
    fractal->min_imag -= half_height_change + (center_y / HEIGHT) * height;
    fractal->max_imag = fractal->min_imag + new_height;

	ft_mandel(fractal);
}

//move the fractal
void    ft_move(t_fractal *fractal, double x, double y)
{
	double x_width;
	double y_height;
	double move_x;
	double move_y;

	x_width = fractal->max_real - fractal->min_real;
	y_height = fractal->max_imag - fractal->min_imag; 
	move_x = x * x_width;
	move_y = y * y_height;
	fractal->min_real += move_x;
	fractal->max_real += move_x;
	fractal->min_imag += move_y;
	fractal->max_imag += move_y;
	ft_mandel(fractal);
}

// calculate the pixel color
// z = z^2 + c
// (x^2 - y)^2 = real
// (2xyi) = imaginary
// if hypotenuse is greater than 2, return the number of iterations
int	ft_calc_pixel(double x, double y)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	i = 0;
	z.real = 0;
	z.imag = 0;
	c.real = x;
	c.imag = y;
	while (i < MAX_ITER)
	{
		tmp.real = z.real * z.real - z.imag * z.imag + c.real;
		tmp.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp.real;
		z.imag = tmp.imag;
		if (z.real * z.real + z.imag * z.imag > 4)
			return (i);
		i++;
	}
	return (-1);
}

// iterate through pixels and scale them
void	ft_mandel(t_fractal *fractal)
{
	double	x;
	double	y;
	double	scaled_x;
	double	scaled_y;
	int		color;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			scaled_x = (x / WIDTH) * (fractal->max_real - fractal->min_real) + fractal->min_real;
			scaled_y = (y / HEIGHT) * (fractal->max_imag - fractal->min_imag) + fractal->min_imag;
			color = ft_calc_pixel(scaled_x, scaled_y);
			ft_color_pixel(x, y, color, fractal->image);
			x++;
		}
		x = 0;
		y++;
	}
}
