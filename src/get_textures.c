/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:23:56 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/21 02:01:19 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_texture(t_cubed *self, int direction)
{
	int		i;
	int		j;
	t_img	img;

	i = -1;
	img.img = mlx_xpm_file_to_image(self.mlx_ptr, self.map->texture_paths[direction], &img.img_width, &img.img_height);
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			self->texture[direction][]
		}
	}
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
