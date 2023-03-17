/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breseham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:00:39 by harndt            #+#    #+#             */
/*   Updated: 2023/03/17 19:20:18 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Function to input pixels on the screen.
 * 
 * @param img Address to the image structure.
 * @param x Position on x axys.
 * @param y Position on y axys.
 * @param color Color to paint the pixel.
 */
void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

/**
 * @brief Calculates the mod form the given number.
 * 
 * @param value Value to calculate mod.
 * @return int Mod value;
 */
static int	find_mod(float value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

/**
 * @brief Compares and found the larger value.
 * 
 * @param a First value to be compared.
 * @param b Second value to be compared.
 * @return int The larger value.
 */
static int	find_max(float a, float b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

void	breseham(t_cubed *self, t_line line, int color)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = line.x1 - line.x;
	y_step = line.y1 - line.y;
	max = find_max(find_mod(x_step), find_mod(y_step));
	x_step /= max;
	y_step /= max;
	while (((int)(line.x - line.x1)) || ((int)(line.y - line.y1)))
	{
		put_pixel(&self->img, line.x, line.y, color);
		line.x += x_step;
		line.y += y_step;
	}
}
