/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_checker_vertical.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:57:37 by harndt            #+#    #+#             */
/*   Updated: 2023/03/28 17:33:08 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_vertical_player_add_x(t_cubed *self)
{
	int	player_add_x;

	player_add_x = (self->player.pos_x + self->player.dx) / 64;
	if (player_add_x < 0 || player_add_x > (int)self->map.width)
	{
		if (player_add_x < 0)
			player_add_x = 0;
		else
			player_add_x = self->map.width;
	}
	return (player_add_x);
}

int	check_vertical_player_add_y(t_cubed *self)
{
	int	player_add_y;

	player_add_y = (self->player.pos_y + self->player.dy) / 64;
	if (player_add_y < 0 || player_add_y > (int)self->map.height)
	{
		if (player_add_y < 0)
			player_add_y = 0;
		else
			player_add_y = self->map.height;
	}
	return (player_add_y);
}

int	check_vertical_player_sub_x(t_cubed *self)
{
	int	player_sub_x;

	player_sub_x = (self->player.pos_x - self->player.dx) / 64;
	if (player_sub_x > (int)self->map.width || player_sub_x < 0)
	{
		if (player_sub_x < 0)
			player_sub_x = 0;
		else
			player_sub_x = self->map.width;
	}
	return (player_sub_x);
}

int	check_vertical_player_sub_y(t_cubed *self)
{
	int	player_sub_y;

	player_sub_y = (self->player.pos_y - self->player.dy) / 64;
	if (player_sub_y > (int)self->map.height || player_sub_y < 0)
	{
		if (player_sub_y < 0)
			player_sub_y = 0;
		else
			player_sub_y = self->map.height;
	}
	return (player_sub_y);
}
