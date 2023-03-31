/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:20:39 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/31 19:49:43 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Draws a block
 * 
 * @param self Address to the program structure.
 * @param x Position on x axys.
 * @param y Position on y axys.
 * @param color Color to paint the pixel.
 */
void	draw_block(t_cubed *self, int x, int y, int color)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			if (i == 0 || i == 63 || j == 0 || j == 63)
				put_pixel(&self->img, x * 64 + i, y * 64 + j, 0x0d1117);
			else
				put_pixel(&self->img, x * 64 + i, y * 64 + j, color);
		}
	}
}

/**
 * @brief Draws a player.
 * 
 * @param self Address to the program struct.
 */
void	draw_player(t_cubed *self)
{
	int		i;
	int		j;
	t_line	line;

	i = -4;
	while (++i < 5)
	{
		j = -4;
		while (++j < 5)
		{
			put_pixel(&self->img, self->player.pos_x + j, \
					self->player.pos_y + i, 0x00FF00);
		}
	}
	check_player_dir(&self->player);
	line = get_line(self->player.pos_x, self->player.pos_y, \
			self->player.dx + self->player.pos_x, self->player.dy + \
			self->player.pos_y);
	bresenham(self, line, 0xFF0000);
}

/**
 * @brief Projects the 2D map in 3D.
 * 
 * @param self Address to the program struc.
 * @param i Index.
 */
void	draw_3d(t_cubed *self, int i)
{
	int		j;
	float	ca;

	ca = self->player.dir - self->ray.angle;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	self->ray.dist = self->ray.dist * cos(ca);
	self->ray.height = (CUBE_SIZE * W_HEIGHT) / self->ray.dist;
	self->ray.start = W_HEIGHT / 2 - self->ray.height / 2;
	self->ray.end = W_HEIGHT / 2 + self->ray.height / 2;
	if (get_color(self->map.color_ceiling) == 256 || \
		get_color(self->map.color_floor) == 256)
	{
		msg(STR_ERR_RGB, NULL, FALSE);
		mlx_destroy_image(self->mlx_ptr, self->img.img);
		end_program(self);
	}
	j = -1;
	while (++j < self->ray.start)
		put_pixel(&self->img, i, j, get_color(self->map.color_ceiling));
	j--;
	draw_wall(self, i, j);
	j = self->ray.end -2;
	while (++j < W_HEIGHT)
		put_pixel(&self->img, i, j, get_color(self->map.color_floor));
}

/**
 * @brief Draws field of vision.
 * 
 * @param self Address to the program struct.
 */
void	draw_rays(t_cubed *self)
{
	int	i;

	i = -1;
	self->ray.angle = self->player.dir - FOV / 2;
	if (self->ray.angle < 0)
		self->ray.angle += 2 * PI;
	if (self->ray.angle > 2 * PI)
		self->ray.angle -= 2 * PI;
	while (++i < 640)
	{
		init_ray(self);
		draw_3d(self, i);
		self->ray.angle = self->player.dir + FOV / 2 - FOV * i / W_WIDTH;
		if (self->ray.angle < 0)
			self->ray.angle += 2 * PI;
		if (self->ray.angle > 2 * PI)
			self->ray.angle -= 2 * PI;
	}
}

/**
 * @brief Draws the map enviroment.
 * 
 * @param self Address to the program struct.
 */
void	draw(t_cubed *self)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	y = -1;
	init_img(&self->img, self);
	while (++y < (int)self->map.height)
	{
		while (++x < (int)self->map.width - 1)
		{
			if (self->map.map[y][x] == '1')
				color = 0xFFFFFF;
			else
				color = 0x000000;
			draw_block(self, x, y, color);
		}
		x = -1;
	}
	draw_player(self);
	draw_rays(self);
	mlx_put_image_to_window(self->mlx_ptr, self->win_ptr, self->img.img, 0, 0);
	mlx_destroy_image(self->mlx_ptr, self->img.img);
}
