/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:54:43 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/28 20:20:57 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//change color
void	ft_change_color(t_fractal *f)
{
	if (f->color_fractal == 1)
		f->color_fractal = 2;
	else if (f->color_fractal == 2)
		f->color_fractal = 3;
	else if (f->color_fractal == 3)
		f->color_fractal = 4;
	else if (f->color_fractal == 4)
		f->color_fractal = 1;
	ft_fractal_prep(f);
}

//determine colors
void	ft_color_pixel(int x, int y, int color, t_fractal *f)
{
	if (f->color_fractal == 1)
		ft_psychedelic(x, y, color, f);
	else if (f->color_fractal == 2)
		ft_golden(x, y, color, f);
	else if (f->color_fractal == 3)
		ft_bubblegum(x, y, color, f);
	else if (f->color_fractal == 4)
		ft_new(x, y, color, f);
}
