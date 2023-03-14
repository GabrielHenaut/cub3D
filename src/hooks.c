/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:40:24 by harndt            #+#    #+#             */
/*   Updated: 2023/03/14 19:01:11 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Redraws the screen when the window is refocused.
 *
 * @param data Address to the program struct.
 * @return int 0
 */
static int	rerender(t_cubed *data)
{
	draw(data);
	return (0);
}

/**
 * @brief Moves the player in the given direction.
 * 
 * @param self Address to program structure.
 * @param dir Direction to move into.
 */
void	move_player(t_cubed *self, int dir)
{
	int		x;
	int		y;

	x = self->player.pos_array_x;
	y = self->player.pos_array_y;
	if (dir == 0)
	{
		if (self->map.map[y - 1][x] == '0')
		{
			self->player.pos_y += self->player.dy;
			self->player.pos_x += self->player.dx;
		}
	}
	else if (dir == 1)
	{
		if (self->map.map[y + 1][x] == '0')
		{
			self->player.pos_y -= self->player.dy;
			self->player.pos_x -= self->player.dx;
		}
	}
}

/**
 * @brief Rotates the player in the given direction.
 * 
 * @param self Address to the program structure.
 * @param dir Direction to rotate into.
 */
void	rotate_player(t_cubed *self, int dir)
{
	if (dir == 0)
	{
		self->player.dir -= 0.1;
		if (self->player.dir < 0)
			self->player.dir = 2 * PI;
		self->player.dx = cos(self->player.dir) * SCALE_FACTOR;
		self->player.dy = sin(self->player.dir) * SCALE_FACTOR;
	}
	else if (dir == 1)
	{
		self->player.dir += 0.1;
		if (self->player.dir > 2 * PI)
			self->player.dir = 0;
		self->player.dx = cos(self->player.dir) * SCALE_FACTOR;
		self->player.dy = sin(self->player.dir) * SCALE_FACTOR;
	}
}

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
	if (keysym == KEY_W)
		move_player(self, 0);
	if (keysym == KEY_S)
		move_player(self, 1);
	if (keysym == KEY_A)
		rotate_player(self, 0);
	if (keysym == KEY_D)
		rotate_player(self, 1);
	rerender(self);
	return (EXIT_SUCCESS);
}

/**
 * @brief Set the hooks to capture the close window event on the "X" button, 
 * and on the key release.
 * 
 * @param self Address to the program struct.
 */
void	set_hooks(t_cubed *self)
{
	mlx_hook(self->win_ptr, KEYPRESS, KEYPRESSMASK, press_key, self);
	mlx_hook(self->win_ptr, REFOCUS, (1L << 04), rerender, self);
	mlx_hook(self->win_ptr, DESTROY, DESTROYMASK, end_program, self);
	return ;
}
