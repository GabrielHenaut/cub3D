/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:17:12 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/22 22:45:14 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_dir(t_cubed *self)
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
		if (self->ray.angle > PI / 2 && self->ray.angle < 3 * PI / 2)
			return (WE);
		else
			return (EA);
	}
}

void	draw_wall(t_cubed *self, int i, int j)
{
	int		dir;
	float	tex_y;
	float	tex_y_step;
	float	tex_y_offset;
	int		counter;
	float	tex_x;

	dir = get_dir(self);
	tex_y_step = 64.0 / self->ray.height;
	tex_y_offset = 1;
	if (self->ray.height > W_HEIGHT)
	{
		tex_y_offset = (self->ray.height - W_HEIGHT) / 2;
		self->ray.height = W_HEIGHT;
	}
	tex_y = tex_y_offset * tex_y_step;
	if (self->ray.hit == 1)
	{
		tex_x = (int)(self->ray.x / 2) % 64;
		if (dir == SO)
			tex_x = 64 - tex_x - 1;
	}
	else
	{
		tex_x = (int)(self->ray.y / 2) % 64;
		if (dir == WE)
			tex_x = 64 - tex_x - 1;
	}
	counter = -1;
	while (++counter < self->ray.height)
	{
		put_pixel(&self->img, i, j + counter, self->ray.texture[dir][(int)tex_y * 64 + (int)tex_x]);
		tex_y += tex_y_step;
	}
}

