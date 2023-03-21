/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghosthologram@student.42sp.org.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:23:56 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/20 21:31:16 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_texture(t_cubed *self, int direction)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 64)
	{

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
