/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:29:09 by harndt            #+#    #+#             */
/*   Updated: 2023/03/31 19:13:46 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Redraws the screen when the window is refocused.
 *
 * @param data Address to the program struct.
 * @return int 0
 */
int	rerender(t_cubed *data)
{
	draw(data);
	return (0);
}

/**
 * @brief Get the line.
 * 
 * @param x Begining of the x line.
 * @param y Begining of the y line.
 * @param x1 Ending of the x line.
 * @param y1 Ending of the y line.
 * @return t_line Address to the created line struct.
 */
t_line	get_line(int x, int y, int x1, int y1)
{
	t_line	line;

	line.x = x;
	line.y = y;
	line.x1 = x1;
	line.y1 = y1;
	return (line);
}

/**
 * @brief Calculates de line distance.
 * 
 * @param x1 Begining of the x line.
 * @param y1 Begining of the y line.
 * @param x2 Ending of the x line.
 * @param y2 Ending of the y line.
 * @return float The calculated distance.
 */
float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

/**
 * @brief Checks the player direction.
 * 
 * @param player Address to the player struct.
 */
void	check_player_dir(t_player *player)
{
	if (player->dir > PI)
		player->dir_x = -1;
	else
		player->dir_x = 1;
	if (player->dir > P2 && player->dir < P3)
		player->dir_y = -1;
	else
		player->dir_y = 1;
}

/**
 * @brief Finds the map width.
 * 
 * @param data Addres to the program structure.
 * @param fd Map file descriptor ID.
 */
void	find_map_width(t_cubed *data, int fd)
{
	char	*line;

	line = skip_to_map(fd);
	while (line && ++data->map.height)
	{
		if (ft_strlen(line) > data->map.width)
			data->map.width = ft_strlen(line);
		line = next_line(line, fd);
	}
	free(line);
}
