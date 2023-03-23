/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:17:12 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/23 16:27:14 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Get the direction the player is facing.
 * 
 * @param self Address to the program struct.
 * @return int The direction as e_num e_directions.
 */
int	get_dir(t_cubed *self)
{
	if (self->ray.hit == 1)
	{
		if (self->ray.angle > PI)
			return (SO);
		else
			return (NO);
	}
	else
	{
		if (self->ray.angle > P2 && self->ray.angle < P3)
			return (WE);
		else
			return (EA);
	}
}

/**
 * @brief Recalculates tex_x base on wall proximity.
 * 
 * @param self Addres to the program struct.
 * @param tex_x Texture x offset.
 * @return float The texture recalculate in case of  hit, else tex_x.
 */
static float	check_ray_hit(t_cubed *self, float tex_x)
{
	if (self->ray.hit == 1)
	{
		tex_x = (int)(self->ray.x / 2) % 64;
		if (get_dir(self) == SO)
			return (tex_x = 64 - tex_x - 1);
	}
	else
	{
		tex_x = (int)(self->ray.y / 2) % 64;
		if (get_dir(self) == WE)
			return (tex_x = 64 - tex_x - 1);
	}
	return (tex_x);
}

/**
 * @brief Draws a wall.
 * 
 * @param self Address to the program struct.
 * @param i Column array index.
 * @param j Row array index.
 */
void	draw_wall(t_cubed *self, int i, int j)
{
	float	tex_y;
	float	tex_y_step;
	float	tex_y_offset;
	int		counter;
	float	tex_x;

	tex_y_step = 64.0 / self->ray.height;
	tex_y_offset = 1;
	if (self->ray.height > W_HEIGHT)
	{
		tex_y_offset = (self->ray.height - W_HEIGHT) / 2;
		self->ray.height = W_HEIGHT;
	}
	tex_y = tex_y_offset * tex_y_step;
	tex_x = 0;
	tex_x = check_ray_hit(self, tex_x);
	counter = -1;
	while (++counter < self->ray.height)
	{
		put_pixel(&self->img, i, j + counter, \
		self->ray.texture[get_dir(self)][(int)tex_y * 64 + (int)tex_x]);
		tex_y += tex_y_step;
	}
}
