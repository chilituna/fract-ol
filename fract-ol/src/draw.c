/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:54:43 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/13 19:58:24 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// color pixel to image
void	ft_color_pixel(int x, int y, int color, mlx_image_t *image)
{
	if (color == -1)
		color = 0x000000FF;
	else 
		color = 0xFCBE11FF * color;
	mlx_put_pixel(image, x, y, color);

	// if (color == -1)
	// {
	// 	mlx_put_pixel(image, x, y, 0x000000FF);  // Set the background color for points inside the Mandelbrot set
	// }
	// else
	// {
	// 	// Define the start and end colors for the gradient
	// 	int start_color = 0x000000FF;   // Black
	// 	int end_color = 0xFCBE11FF;     // Gold

	// 	// Interpolate the color based on the number of iterations
	// 	double t = (double)color / MAX_ITER;
	// 	int red = (int)((1 - t) * ((start_color >> 24) & 0xFF) + t * ((end_color >> 24) & 0xFF));
	// 	int green = (int)((1 - t) * ((start_color >> 16) & 0xFF) + t * ((end_color >> 16) & 0xFF));
	// 	int blue = (int)((1 - t) * ((start_color >> 8) & 0xFF) + t * ((end_color >> 8) & 0xFF));
	// 	int alpha = (int)((1 - t) * (start_color & 0xFF) + t * (end_color & 0xFF));

	// 	int interpolated_color = (red << 24) | (green << 16) | (blue << 8) | alpha;

	// 	mlx_put_pixel(image, x, y, interpolated_color);
	// }
}
