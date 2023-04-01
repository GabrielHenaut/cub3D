/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:46:49 by harndt            #+#    #+#             */
/*   Updated: 2023/04/01 14:47:16 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	calculate_ca(t_cubed *self)
{
	float	ca;

	ca = self->player.dir - self->ray.angle;
	if (ca < 0)
		return (ca += 2 * PI);
	if (ca > 2 * PI)
		return (ca -= 2 * PI);
	return (ca);
}
