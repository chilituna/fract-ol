/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:07:57 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/28 20:54:32 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// calculate the pixel color for mandelbrot
// z = z^2 + c
// (x^2 - y)^2 = real
// (2xyi) = imaginary
// if hypotenuse is greater than 2, return the number of iterations
int	ft_calc_mandel(double x, double y, t_fractal *f)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	i = 0;
	z.real = f->input.real;
	z.imag = f->input.imag;
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

// calculate the pixel color for julia
// otherwise same as mandelbrot but with a constant input
int	ft_calc_julia(double x, double y, t_fractal *fractal)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	i = 0;
	z.real = x;
	z.imag = y;
	c.real = fractal->input.real;
	c.imag = fractal->input.imag;
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

// calculate the pixel color for burning ship
// otherwise same as mandelbrot but imaginary part is always positive
int	ft_calc_burning(double x, double y, t_fractal *fractal)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	i = 0;
	z.real = fractal->input.real;
	z.imag = fractal->input.imag;
	c.real = x;
	c.imag = y;
	while (i < MAX_ITER)
	{
		tmp.real = z.real * z.real - z.imag * z.imag + c.real;
		tmp.imag = 2 * fabs(z.real * z.imag) + c.imag;
		z.real = tmp.real;
		z.imag = tmp.imag;
		if (z.real * z.real + z.imag * z.imag > 4)
			return (i);
		i++;
	}
	return (-1);
}

//select the fractal to draw
int	ft_select_fractal(double scaled_x, double scaled_y, t_fractal *f)
{
	if (f->name[0] == 'm') 
		return (ft_calc_mandel(scaled_x, scaled_y, f));
	else if (f->name[0] == 'j')
		return (ft_calc_julia(scaled_x, scaled_y, f));
	else if (f->name[0] == 'b')
		return (ft_calc_burning(scaled_x, scaled_y, f));
	return (0);
}

// iterate through pixels and scale them
// set the color of the pixel
// draw the pixel to the image
void	ft_fractal_prep(t_fractal *f)
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
			scaled_x = (x / WIDTH) * (f->max.real - f->min.real) + f->min.real;
			scaled_y = (y / HEIGHT) * (f->max.imag - f->min.imag) + f->min.imag;
			color = ft_select_fractal(scaled_x, scaled_y, f);
			ft_color_pixel(x, y, color, f);
			x++;
		}
		x = 0;
		y++;
	}
}
