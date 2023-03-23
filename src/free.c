/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:58:23 by harndt            #+#    #+#             */
/*   Updated: 2023/03/23 16:32:28 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Frees the allocated memmory where the diretion textures are stored.
 * 
 * @param self Address to the program struct.
 */
void	free_textures(t_cubed *self)
{
	int	i;

	i = -1;
	while (++i < 4)
		free(self->map.texture_paths[i]);
}

/**
 * @brief Frees program data.
 * 
 * @param data Addres to the program structure.
 */
void	free_data(t_cubed *data)
{
	size_t	i;

	i = -1;
	while (++i < data->map.height)
		free(data->map.map[i]);
	free_textures(data);
	free(data->map.map);
	free(data->map.color_floor);
	free(data->map.color_ceiling);
}

/**
 * @brief Frees found struct.
 * 
 * @param data Address to the program struct.
 * @param found Addres to the foun struct.
 * @param fd Map file descriptor ID.
 */
void	free_found(t_cubed *data, t_founds found, int fd)
{
	if (found.north == 1)
		free(data->map.texture_paths[NO]);
	if (found.south == 1)
		free(data->map.texture_paths[SO]);
	if (found.west == 1)
		free(data->map.texture_paths[WE]);
	if (found.east == 1)
		free(data->map.texture_paths[EA]);
	if (found.floor == 1)
		free(data->map.color_floor);
	if (found.ceiling == 1)
		free(data->map.color_ceiling);
	close(fd);
	exit_error(".cub file structure incorect");
}
