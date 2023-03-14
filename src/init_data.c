/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:29:12 by harndt            #+#    #+#             */
/*   Updated: 2023/03/12 23:03:48 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Initiates the player.
 * 
 * @param data Address to the program struct.
 */
void	init_player(t_cubed *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S' || data->map.map[i][j] == 'E' || data->map.map[i][j] == 'W')
			{
				data->player.pos_x = j * 64 + 31;
				data->player.pos_y = i * 64 + 31;
				data->player.pos_array_x = j;
				data->player.pos_array_y = i;
				if (data->map.map[i][j] == 'N')
					data->player.dir = PI / 2;
				else if (data->map.map[i][j] == 'S')
					data->player.dir = PI;
				else if (data->map.map[i][j] == 'E')
					data->player.dir = 0;
				else if (data->map.map[i][j] == 'W')
					data->player.dir = (PI * 3) / 2;
			}
		}
	}
	data->player.dx = cos(data->player.dir) * SCALE_FACTOR;
	data->player.dy = sin(data->player.dir) * SCALE_FACTOR;
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
	// print_map(data);
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
