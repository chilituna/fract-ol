/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:32:21 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/28 20:18:47 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define M_PI 3.14159265358979323846

//color functions
void	ft_psychedelic(int x, int y, int color, t_fractal *f)
{
	if (color == -1)
		color = 0x000000FF;
	else 
		color = 0xFCBE11FF * color;
	if (color == 0)
		color = 0xFCBE11FF;
	mlx_put_pixel(f->image, x, y, color);
}

void	ft_golden(int x, int y, int color, t_fractal *f)
{
	double	shading;
	int		red;
	int		green;
	int		blue;

	if (color == -1)
		color = 0x000000FF;
	else 
	{
		shading = (double)color / MAX_ITER;
		shading = shading * 0.8 + 0.2;
		red = (int)(255 * shading * 0.8 + 0.2);
		green = (int)(165 * shading * 0.8 + 0.2);
		blue = (int)(0 * shading * 0.8 + 0.2);
		color = (red << 24) | (green << 16) | (blue << 8) | 0xFF;
	}
	mlx_put_pixel(f->image, x, y, color);
}

void	ft_bubblegum(int x, int y, int color, t_fractal *f)
{
	if (color == -1)
		color = 0x000000FF;
	else
		color = 0xd511fcff * color;
	if (color == 0)
		color = 0xd511fcff;
	mlx_put_pixel(f->image, x, y, color);
}

void	ft_new(int x, int y, int color, t_fractal *f)
{
	double	shading;
	int		red;
	int		green;
	int		blue;

	if (color == -1)
		color = 0x000000FF;
	else
	{
		shading = (double)color / MAX_ITER;
		shading = shading * 0.8 + 0.2;
		red = 0x28;
		green = 0x00;
		blue = (int)(255 * shading * 0.8 + 0.2);
		color = (red << 24) | (green << 16) | (blue << 8) | 0xFF;
	}
	mlx_put_pixel(f->image, x, y, color);
}
