/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:54:37 by harndt            #+#    #+#             */
/*   Updated: 2023/04/01 15:50:38 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Checks if a string contains RGB values.
 * 
 * @param color Address to color struct.
 * @param str String to check.
 * @return t_bool TRUE if RGB values are found, else FALSE.
 */
static t_bool	check_rgb_str(t_color *color, char *str)
{
	int		counter;

	if (*str == ',')
		return (FALSE);
	color->r = ft_atoi(str);
	while (*str && *str != ',')
		if (!ft_isdigit(*str++))
			return (FALSE);
	if (*(++str) == ',')
		return (FALSE);
	color->g = ft_atoi(str);
	while (*str && *str != ',')
		if (!ft_isdigit(*str++))
			return (FALSE);
	if (!ft_isdigit(*(++str)))
		return (FALSE);
	color->b = ft_atoi(str);
	counter = -1;
	while (++counter < 3 && ft_isdigit(*str))
		str++;
	if (*str && *str != '\n')
		return (FALSE);
	return (TRUE);
}

/**
 * @brief Get the color in RGB
 * 
 * @param str Color code in hexadecimal.
 * @return unsigned long The color in RGB.
 */
unsigned long	get_color(char *str)
{
	t_color	color;

	if (!check_rgb_str(&color, str))
		return (256);
	if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255 || \
		color.b < 0 || color.b > 255)
		return (256);
	return (((color.r & 0xff) << 16) + \
		((color.g & 0xff) << 8) + (color.b & 0xff));
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
