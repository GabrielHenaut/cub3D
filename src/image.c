/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:54:37 by harndt            #+#    #+#             */
/*   Updated: 2023/03/23 16:36:41 by harndt           ###   ########.fr       */
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

	r = ft_atoi(str);
	while (*str && *str != ',')
		str++;
	str++;
	g = ft_atoi(str);
	while (*str && *str != ',')
		str++;
	str++;
	b = ft_atoi(str);
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
