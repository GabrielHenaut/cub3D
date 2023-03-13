/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:40:24 by harndt            #+#    #+#             */
/*   Updated: 2023/03/12 16:47:42 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Handles the events when a key is presses on the keyboard.
 * 
 * @param keysym The pressed key.
 * @param self Address to the program struct.
 * @return int 1
 */
int	press_key(int keysym, t_cubed *self)
{
	if (keysym == KEY_ESC)
		end_program(self);
	printf("keysym = |%d|\n", keysym);
	return (EXIT_SUCCESS);
}

/**
 * @brief Redraws the screen when the window is refocused.
 *
 * @param data Address to the program struct.
 * @return int 0
 */
static int	rerender(t_cubed *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

/**
 * @brief Set the hooks to capture the close window event on the "X" button, 
 * and on the key release.
 * 
 * @param self Address to the program struct.
 */
void	set_hooks(t_cubed *self)
{
	mlx_hook(self->win_ptr, DESTROY, DESTROYMASK, end_program, self);
	// mlx_hook(self->win_ptr, REFOCUS, (1L << 04), rerender, &self);
	mlx_hook(self->win_ptr, KEYRELEASE, KEYRELEASEMASK, &press_key, self);
	return ;
}
