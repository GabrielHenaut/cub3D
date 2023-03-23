/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:10:10 by harndt            #+#    #+#             */
/*   Updated: 2023/03/23 16:40:24 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Set the horizontal direction to be checked.
 * 
 * @param self Address to the program struct.
 * @param arc_tan Arc tangent from the player view angle.
 */
void	set_h_angle(t_cubed *self, double arc_tan)
{
	if (self->ray.angle < PI)
	{
		self->ray.y = ((int)self->player.pos_y / 64) * 64 - 0.0001;
		self->ray.x = (self->player.pos_y - self->ray.y) * arc_tan + \
		self->player.pos_x;
		self->ray.step_y = -64;
		self->ray.step_x = -self->ray.step_y * arc_tan;
	}
	else if (self->ray.angle > PI)
	{
		self->ray.y = ((int)self->player.pos_y / 64) * 64 + 64;
		self->ray.x = (self->player.pos_y - self->ray.y) * arc_tan + \
		self->player.pos_x;
		self->ray.step_y = 64;
		self->ray.step_x = -self->ray.step_y * arc_tan;
	}
	if (self->ray.angle == 0 || self->ray.angle == PI)
	{
		self->ray.x = self->player.pos_x;
		self->ray.y = self->player.pos_y;
		self->ray.dof = self->map.height * self->map.width;
	}
}

/**
 * @brief Cast rays to check the horizontal walls.
 * 
 * @param self Address to the program struct.
 */
void	cast_h_rays(t_cubed *self)
{
	self->ray.dof = 0;
	while (self->ray.dof < 8)
	{
		self->ray.map_x = (int)self->ray.x / 64;
		if (self->ray.map_x >= (int)self->map.width)
			self->ray.map_x = self->map.width - 1;
		if (self->ray.map_x < 0)
			self->ray.map_x = 0;
		self->ray.map_y = (int)self->ray.y / 64;
		if (self->ray.map_y >= (int)self->map.height)
			self->ray.map_y = self->map.height - 1;
		if (self->ray.map_y < 0)
			self->ray.map_y = 0;
		if (self->map.map[self->ray.map_y][self->ray.map_x] == '1')
		{
			self->ray.h_x = self->ray.x;
			self->ray.h_y = self->ray.y;
			self->ray.dist_h = distance(self->player.pos_x, \
			self->player.pos_y, self->ray.x, self->ray.y);
			break ;
		}
		self->ray.x += self->ray.step_x;
		self->ray.y += self->ray.step_y;
		self->ray.dof++;
	}
}

/**
 * @brief Set the vertical direction to be checked.
 * 
 * @param self Address to the program struct.
 * @param tg Tangent from the player view angle.
 */
void	set_v_angle(t_cubed *self, double tg)
{
	if (self->ray.angle > P2 && self->ray.angle < P3)
	{
		self->ray.x = ((int)self->player.pos_x / 64) * 64 - 0.0001;
		self->ray.y = (self->player.pos_x - self->ray.x) * tg + \
		self->player.pos_y;
		self->ray.step_x = -64;
		self->ray.step_y = -self->ray.step_x * tg;
	}
	else if (self->ray.angle < P2 || self->ray.angle > P3)
	{
		self->ray.x = ((int)self->player.pos_x / 64) * 64 + 64;
		self->ray.y = (self->player.pos_x - self->ray.x) * tg + \
		self->player.pos_y;
		self->ray.step_x = 64;
		self->ray.step_y = -self->ray.step_x * tg;
	}
	if (self->ray.angle == P3 || self->ray.angle == P2)
	{
		self->ray.x = self->player.pos_x;
		self->ray.y = self->player.pos_y;
		self->ray.dof = self->map.height * self->map.width;
	}
}

/**
 * @brief Cast rays to check the vertical walls.
 * 
 * @param self Address to the program struct.
 */
void	cast_v_rays(t_cubed *self)
{
	self->ray.dof = 0;
	while (self->ray.dof < 8)
	{
		self->ray.map_x = (int)self->ray.x / 64;
		if (self->ray.map_x >= (int)self->map.width)
			self->ray.map_x = self->map.width - 1;
		if (self->ray.map_x < 0)
			self->ray.map_x = 0;
		self->ray.map_y = (int)self->ray.y / 64;
		if (self->ray.map_y >= (int)self->map.height)
			self->ray.map_y = self->map.height - 1;
		if (self->ray.map_y < 0)
			self->ray.map_y = 0;
		if (self->map.map[self->ray.map_y][self->ray.map_x] == '1')
		{
			self->ray.v_x = self->ray.x;
			self->ray.v_y = self->ray.y;
			self->ray.dist_v = distance(self->player.pos_x, \
			self->player.pos_y, self->ray.x, self->ray.y);
			break ;
		}
		self->ray.x += self->ray.step_x;
		self->ray.y += self->ray.step_y;
		self->ray.dof++;
	}
}

/**
 * @brief Calculates wall shades/texture based on the player position.
 * 
 * @param self Address to the program struct.
 */
void	calculate_shade(t_cubed *self)
{
	if (self->ray.dist_h < self->ray.dist_v)
	{
		self->ray.shade = 0.5;
		self->ray.x = self->ray.h_x;
		self->ray.y = self->ray.h_y;
		self->ray.dist = self->ray.dist_h;
		self->ray.color = 0x00CF00;
		self->ray.hit = 1;
	}
	else
	{
		self->ray.x = self->ray.v_x;
		self->ray.y = self->ray.v_y;
		self->ray.dist = self->ray.dist_v;
		self->ray.color = 0x00FC00;
		self->ray.hit = -1;
	}
}
