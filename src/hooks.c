/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <humberto.arndt@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:40:24 by harndt            #+#    #+#             */
/*   Updated: 2023/03/31 20:21:19 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Moves the player left and rigth.
 * 
 * @param self Address to program structure.
 * @param dir Direction to move into.
 */
void	move_player_side(t_cubed *self, int dir)
{
	int		player_add_x;
	int		player_add_y;
	int		player_sub_x;
	int		player_sub_y;

	if (!check_pos_array(self))
		return ;
	player_add_x = check_horizontal_player_add_x(self);
	player_add_y = check_horizontal_player_add_y(self);
	player_sub_x = check_horizontal_player_sub_x(self);
	player_sub_y = check_horizontal_player_sub_y(self);
	if (dir == 0)
	{
		if (self->map.map[self->player.pos_array_y][player_add_x] != '1')
			self->player.pos_x += self->player.dy;
		if (self->map.map[player_add_y][self->player.pos_array_x] != '1')
			self->player.pos_y -= self->player.dx;
	}
	else if (dir == 1)
	{
		if (self->map.map[self->player.pos_array_y][player_sub_x] != '1')
			self->player.pos_x -= self->player.dy;
		if (self->map.map[player_sub_y][self->player.pos_array_x] != '1')
			self->player.pos_y += self->player.dx;
	}
}

/**
 * @brief Moves the player back and forth.
 * 
 * @param self Address to program structure.
 * @param dir Direction to move into.
 */
void	move_player(t_cubed *self, int dir)
{
	int		player_add_x;
	int		player_add_y;
	int		player_sub_x;
	int		player_sub_y;

	if (!check_pos_array(self))
		return ;
	player_add_x = check_vertical_player_add_x(self);
	player_add_y = check_vertical_player_add_y(self);
	player_sub_x = check_vertical_player_sub_x(self);
	player_sub_y = check_vertical_player_sub_y(self);
	printf("pos_array_x: %d player_sub_y: %d\n", self->player.pos_array_x, player_sub_y);
	if (dir == 0)
	{
		if (self->map.map[self->player.pos_array_y][player_sub_x] != '1')
			self->player.pos_x += self->player.dx;
		if (self->map.map[player_sub_y][self->player.pos_array_x] != '1')
			self->player.pos_y += self->player.dy;
	}
	else if (dir == 1)
	{
		if (self->map.map[self->player.pos_array_y][player_add_x] != '1')
			self->player.pos_x -= self->player.dx;
		if (self->map.map[player_add_y][self->player.pos_array_x] != '1')
			self->player.pos_y -= self->player.dy;
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
		self->player.dy = (sin(self->player.dir) * SCALE_FACTOR) * -1;
	}
	else if (dir == 1)
	{
		self->player.dir += 0.1;
		if (self->player.dir > 2 * PI)
			self->player.dir = 0;
		self->player.dx = cos(self->player.dir) * SCALE_FACTOR;
		self->player.dy = (sin(self->player.dir) * SCALE_FACTOR) * -1;
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
		move_player_side(self, 0);
	if (keysym == KEY_D)
		move_player_side(self, 1);
	if (keysym == KEY_LEFT)
		rotate_player(self, 1);
	if (keysym == KEY_RIGHT)
		rotate_player(self, 0);
	draw(self);
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
