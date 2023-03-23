/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:58:35 by harndt            #+#    #+#             */
/*   Updated: 2023/03/23 16:10:49 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ray(t_cubed *self)
{
	double	tg;
	double	arc_tan;

	arc_tan = 1 / tan(self->ray.angle);
	self->ray.dist_h = 10000000;
	self->ray.map_x = self->player.pos_array_x;
	self->ray.map_y = self->player.pos_array_y;
	self->ray.shade = 1;
	set_h_angle(self, arc_tan);
	cast_h_rays(self);
	tg = tan(self->ray.angle);
	self->ray.dist_v = 10000000;
	if (tg < -600)
		tg = -600;
	if (tg > 600)
		tg = 600;
	set_v_angle(self, tg);
	cast_v_rays(self);
	calculate_shade(self);
}
