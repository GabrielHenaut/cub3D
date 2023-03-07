/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/07/01 18:14:35 by ghenaut-		  #+#	#+#			 */
/*   Updated: 2023/03/06 20:44:14 by ghenaut-         ###   ########.fr       */
/*																			*/
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
	int	 fd;


	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_error("Error opening .cub file");
	get_textures(data, fd);
	close(fd);
	// get_map(data, fd);
}

void	init_game(t_cubed *data, char *map_path)
{
	init_player(data);
	init_map(data, map_path);
}
