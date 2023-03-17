/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:11:06 by harndt            #+#    #+#             */
/*   Updated: 2023/03/17 18:20:18 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Get the direction the player stands based on the radian cirlce.
 * 
 * @param self Addres to the program struct.
 * @param i Index to the x on the **map array.
 * @param j Index to the j on the **map array.
 */
static void	get_direction_radian(t_cubed *self, int i, int j)
{
	if (self->map.map[i][j] == 'N')
		self->player.dir = PI / 2;
	else if (self->map.map[i][j] == 'S')
		self->player.dir = (PI * 3) / 2;
	else if (self->map.map[i][j] == 'E')
		self->player.dir = 0;
	else if (self->map.map[i][j] == 'W')
		self->player.dir = PI;
}

/**
 * @brief Initiates the player.
 * 
 * @param data Address to the program struct.
 */
void	init_player(t_cubed *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S' || \
				data->map.map[i][j] == 'E' || data->map.map[i][j] == 'W')
			{
				data->player.pos_x = j * 64 + 31;
				data->player.pos_y = i * 64 + 31;
				data->player.pos_array_x = j;
				data->player.pos_array_y = i;
				get_direction_radian(data, i, j);
			}
		}
	}
	data->player.dx = cos(data->player.dir) * SCALE_FACTOR;
	data->player.dy = (sin(data->player.dir) * SCALE_FACTOR) * -1;
}

/**
 * @brief Initiates the map.
 * 
 * @param data Address to the program struct.
 * @param map_path Path to the map file.
 */
void	init_map(t_cubed *data, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_error("Error opening .cub file");
	data->map.width = 0;
	data->map.height = 0;
	get_textures_path(data, fd);
	close(fd);
	get_map(data, map_path);
	if (validate_map(data))
	{
		free_data(data);
		exit_error("Invalid map structure");
	}
}

/**
 * @brief Initiates the game.
 * 
 * @param data Address to the program struct.
 * @param map_path Path to the map file.
 */
void	init_game(t_cubed *data, char *map_path)
{
	init_map(data, map_path);
	init_player(data);
}
