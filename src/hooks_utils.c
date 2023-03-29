/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <humberto.arndt@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:00:29 by harndt            #+#    #+#             */
/*   Updated: 2023/03/29 16:07:09 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Calculates and verifies if the pos_array position are ok to check 
 collisions.
 * 
 * @param self Stru
 * @return t_bool When not ok FALSE, else TRUE.
 */
t_bool	check_pos_array(t_cubed *self)
{
	self->player.pos_array_x = (int)self->player.pos_x / 64;
	self->player.pos_array_y = (int)self->player.pos_y / 64;
	if (self->player.pos_array_x < 0)
		return (FALSE);
	if (self->player.pos_array_y < 0)
		return (FALSE);
	if (self->player.pos_array_x > (int)self->map.width - 3)
		return (FALSE);
	if (self->player.pos_array_y > (int)self->map.height - 2)
		return (FALSE);
	return (TRUE);
}
