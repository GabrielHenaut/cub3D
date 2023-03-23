/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:23:56 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/23 14:09:54 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Get the texture from the .xpm file.
 * 
 * @param self Address to the program struct.
 * @param direction Direction of the texture.
 */
void	get_texture(t_cubed *self, int direction)
{
	int		i;
	int		j;
	t_img	img;

	img.img = mlx_xpm_file_to_image(self->mlx_ptr, \
			self->map.texture_paths[direction], \
			&img.img_width, &img.img_height);
	if (!img.img)
	{
		msg(STR_ERR_TEXTURE, self->map.texture_paths[direction], TRUE);
		end_program(self);
	}
	img.data = (int *)mlx_get_data_addr(img.img, \
			&img.bits_per_pixel, &img.line_length, &img.endian);
	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			self->ray.texture[direction][img.img_width * i + j] = \
				img.data[img.img_width * i + j];
		}
	}
	mlx_destroy_image(self->mlx_ptr, img.img);
}

/**
 * @brief Get the textures from the .cub file.
 * 
 * @param self Address to the program struct.
 */
void	get_textures(t_cubed *self)
{
	get_texture(self, NO);
	get_texture(self, SO);
	get_texture(self, WE);
	get_texture(self, EA);
}
