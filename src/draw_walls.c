/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghosthologram@student.42sp.org.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:17:12 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/20 22:34:37 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_dir(t_cubed *self)
{
	if (self->ray.angle >= PI /4 && self->ray.angle < 3 * PI / 4)
		return (NO);
	else if (self->ray.angle >= 3 * PI / 4 && self->ray.angle < 5 * PI / 4)
		return (WE);
	else if (self->ray.angle >= 5 * PI / 4 && self->ray.angle < 7 * PI / 4)
		return (SO);
	else
		return (EA);
	return (0);
}																																

void	draw_wall(t_cubed *self, int i, int j)
{
	int		dir;
	float	tex_y;
	float	tex_y_step;
	int		counter;

	dir = get_dir(self);
	tex_y = 0;
	tex_y_step = 64.0 / self->ray.height;
	counter = -1;
	while (++counter < self->ray.height - 1)
	{
		put_pixel(&self->img, i, j + counter, self->ray.texture[dir][(int)tex_y * 64]);
		tex_y += tex_y_step;
	}
}

