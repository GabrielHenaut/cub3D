/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:54:37 by harndt            #+#    #+#             */
/*   Updated: 2023/03/31 20:38:03 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Get the color in RGB
 * 
 * @param str Color code in hexadecimal.
 * @return unsigned long The color in RGB.
 */
unsigned long	get_color(char *str)
{
	int		r;
	int		g;
	int		b;
	int		counter;

	if (*str == ',')
		return (256);
	r = ft_atoi(str);
	while (*str && *str != ',')
	{
		if (!ft_isdigit(*str))
			return (256);
		str++;
	}
	str++;
	if (*str == ',')
		return (256);
	g = ft_atoi(str);
	while (*str && *str != ',')
	{
		if (!ft_isdigit(*str))
			return (256);
		str++;
	}
	str++;
	if (!ft_isdigit(*str))
		return (256);
	b = ft_atoi(str);
	counter = -1;
	while (++counter < 3 && ft_isdigit(*str))
		str++;
	if (*str && *str != '\n')
		return (256);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (256);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

/**
 * @brief Initiates an image struct.
 * 
 * @param img Addres to the image struct.
 * @param data Address to the program struct.
 */
void	init_img(t_img *img, t_cubed *data)
{
	img->img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
			&img->line_length, &img->endian);
}
