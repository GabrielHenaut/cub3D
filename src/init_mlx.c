/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:51:10 by harndt            #+#    #+#             */
/*   Updated: 2023/03/14 19:03:33 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Initiates the mlx struct.
 * 
 * @param self Addres to the program struct.
 */
void	init_mlx(t_cubed *self)
{
	self->mlx_ptr = mlx_init();
	if (!self->mlx_ptr)
	{
		printf("mlx error\n");
		free_data(self);
		exit(1);
	}
	self->win_ptr = mlx_new_window(self->mlx_ptr, W_WIDTH, W_HEIGHT, W_NAME);
	if (!self->win_ptr)
	{
		free(self->win_ptr);
		printf("window error\n");
		free_data(self);
		exit(1);
	}
}
