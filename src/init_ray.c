/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:58:35 by harndt            #+#    #+#             */
/*   Updated: 2023/03/22 20:33:58 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_ray(t_cubed *self)
{
	double	arc_tan;
	double	tg;

	// HORIZONTAL RAYS //
	arc_tan = 1 / tan(self->ray.angle);
	self->ray.dof = 0;
	self->ray.dist_h = 10000000;
	self->ray.map_x = self->player.pos_array_x;
	self->ray.map_y = self->player.pos_array_y;
	if (self->ray.angle < PI)
	{
		self->ray.y = ((int)self->player.pos_y / 64) * 64 - 0.0001;
		self->ray.x = (self->player.pos_y - self->ray.y) * arc_tan + self->player.pos_x;
		self->ray.step_y = -64;
		self->ray.step_x = -self->ray.step_y * arc_tan;
	}
	else if (self->ray.angle > PI)
	{
		self->ray.y = ((int)self->player.pos_y / 64) * 64 + 64;
		self->ray.x = (self->player.pos_y - self->ray.y) * arc_tan + self->player.pos_x;
		self->ray.step_y = 64;
		self->ray.step_x = -self->ray.step_y * arc_tan;
	}
	if (self->ray.angle == 0 || self->ray.angle == PI)
	{
		self->ray.x = self->player.pos_x;
		self->ray.y = self->player.pos_y;
		self->ray.dof = self->map.height * self->map.width;
	}
	while (self->ray.dof < 8)
	// while (self->ray.dof < self->map.height * self->map.width)
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
		// printf(" horizontal map_x = %d, map_y = %d\n", self->ray.map_x, self->ray.map_y);
		// printf(" horizontal x = %i, y = %i\n", self->ray.x, self->ray.y);
		if (self->map.map[self->ray.map_y][self->ray.map_x] == '1')
		{
			self->ray.h_x = self->ray.x;
			self->ray.h_y = self->ray.y;
			self->ray.dist_h = distance(self->player.pos_x, self->player.pos_y, self->ray.x, self->ray.y);
			break ;
		}
		self->ray.x += self->ray.step_x;
		self->ray.y += self->ray.step_y;
		self->ray.dof++;
	}

	// VERTICAL  RAYS //
	self->ray.dof = 0;
	tg = tan(self->ray.angle);
	self->ray.dist_v = 10000000;
	if (tg < -600)
		tg = -600;
	if (tg > 600)
		tg = 600;
	if (self->ray.angle > PI / 2 && self->ray.angle < P3)
	{
		self->ray.x = ((int)self->player.pos_x / 64) * 64 - 0.0001;
		self->ray.y = (self->player.pos_x - self->ray.x) * tg + self->player.pos_y;
		self->ray.step_x = -64;
		self->ray.step_y = -self->ray.step_x * tg;
	}
	else if (self->ray.angle < PI / 2 || self->ray.angle > P3)
	{
		self->ray.x = ((int)self->player.pos_x / 64) * 64 + 64;
		self->ray.y = (self->player.pos_x - self->ray.x) * tg + self->player.pos_y;
		self->ray.step_x = 64;
		self->ray.step_y = -self->ray.step_x * tg;
	}
	if (self->ray.angle == P3 || self->ray.angle == PI / 2)
	{
		self->ray.x = self->player.pos_x;
		self->ray.y = self->player.pos_y;
		self->ray.dof = self->map.height * self->map.width;
	}
	while (self->ray.dof < 8)
	// while (self->ray.dof < self->map.height * self->map.width)
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
		// printf("vertical map_x = %d, map_y = %d\n", self->ray.map_x, self->ray.map_y);
		// printf(" horizontal x = %i, y = %i\n", self->ray.x, self->ray.y);
		if (self->map.map[self->ray.map_y][self->ray.map_x] == '1')
		{
			self->ray.v_x = self->ray.x;
			self->ray.v_y = self->ray.y;
			self->ray.dist_v = distance(self->player.pos_x, self->player.pos_y, self->ray.x, self->ray.y);
			break ;
		}
		self->ray.x += self->ray.step_x;
		self->ray.y += self->ray.step_y;
		self->ray.dof++;
	}
	self->ray.shade = 1;
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
