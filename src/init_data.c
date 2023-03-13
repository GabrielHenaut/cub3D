/* ************************************************************************** */
/*                                                                            */
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

void	init_player(t_cubed *data)
{
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->player.dir_x = 0;
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0;
	data->player.move_speed = 0.1;
	data->player.rot_speed = 0.1;
}

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

void	init_game(t_cubed *data, char *map_path)
{
	init_player(data);
	init_map(data, map_path);
}
