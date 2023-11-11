/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:03:30 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/28 20:48:56 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../Libft/libft.h"
# include "../MLX/MLX42.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define ERROR_MSG "Options:\n./fractol m\n./fractol j <r> <i>\n./fractol b\n"
# define ERROR_JULIA "Error: Julia input must be between -2 and 2\n"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

// typedef struct mlx
// {
// 	void*		window;
// 	void*		context;
// 	int32_t		width;
// 	int32_t		height;
// 	double		delta_time;
// }	mlx_t;

// typedef struct mlx_image
// {
// 	const uint32_t	width;
// 	const uint32_t	height;
// 	uint8_t*		pixels;
// 	mlx_instance_t*	instances;
// 	int32_t			count;
// 	bool			enabled;
// 	void*			context;
// }	mlx_image_t;

// typedef struct mlx_instance
// {
// 	int32_t	x;
// 	int32_t	y;
// 	int32_t	z;
// 	bool	enabled;
// }	mlx_instance_t;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractal
{
	mlx_t			*mlx;
	char			*name;
	mlx_image_t		*image;
	t_complex		min;
	t_complex		max;
	int				color_fractal;
	t_complex		input;
	t_complex		mouse;
	mlx_texture_t	*icon;
}	t_fractal;

//start program
int32_t	main(int argc, char **argv);

//error handling and exit
void	ft_end_program(void *param);
void	ft_input_error(void);
void	ft_julia_error(void);
void	ft_malloc_error(void);

//check input
void	ft_check_input(int argc, char **argv);
int		ft_check_julia(char *real, char *imag);

//initializing and creating fractal
void	ft_create_fractal(char **argv, t_fractal *fractal);
void	ft_initialize_fractal(t_fractal *fractal, char **argv);

//fractals 
int		ft_calc_mandel(double x, double y, t_fractal *fractal);
int		ft_calc_julia(double x, double y, t_fractal *fractal);
int		ft_calc_burning(double x, double y, t_fractal *fractal);
void	ft_fractal_prep(t_fractal *fractal);
int		ft_select_fractal(double scaled_x, double scaled_y, t_fractal *fractal);

//calculations
void	ft_zoom(t_fractal *fractal, double i);
void	ft_move(t_fractal *fractal, double x, double y);
void	ft_mouse_zoom(t_fractal *fractal, double i);
void	ft_zoom_mouse(t_fractal *fractal, double i);
void	ft_move_mouse(t_fractal *fractal, double x_value, double y_value);

//color handling
void	ft_color_pixel(int x, int y, int color, t_fractal *fractal);
void	ft_change_color(t_fractal *fractal);

//colors
void	ft_psychedelic(int x, int y, int color, t_fractal *fractal);
void	ft_golden(int x, int y, int color, t_fractal *fractal);
void	ft_bubblegum(int x, int y, int color, t_fractal *fractal);
void	ft_new(int x, int y, int color, t_fractal *f);

//hooks
void	ft_key_events(struct mlx_key_data key_data, void *param);
void	ft_scroll_events(double xdelta, double ydelta, void *param);
void	ft_m(enum mouse_key b, enum action a, enum modifier_key k, void *param);

#endif
