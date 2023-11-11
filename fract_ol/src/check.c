/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:25:05 by aarponen          #+#    #+#             */
/*   Updated: 2023/11/01 16:03:59 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_check_julia(char *real, char *imag)
{
	double	r;
	double	i;

	r = ft_atod(real);
	i = ft_atod(imag);
	if (r < -2.0 || r > 2.0 || i < -2.0 || i > 2.0)
		return (1);
	return (0);
}

//check input
void	ft_check_input(int argc, char **argv)
{
	if ((argc == 2 && argv[1][0] == 'm' && argv[1][1] == '\0') 
		|| (argc == 2 && argv[1][0] == 'b' && argv[1][1] == '\0'))
		return ;
	else if (argc == 4 && argv[1][0] == 'j' && argv[1][1] == '\0'
		&& ft_check_julia(argv[2], argv[3]) == 1)
		ft_julia_error();
	else if (argc == 4 && argv[1][0] == 'j' && argv[1][1] == '\0'
		&& ft_check_julia(argv[2], argv[3]) == 0)
		return ;
	else
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
