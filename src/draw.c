/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:20:39 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/21 04:07:56 by harndt           ###   ########.fr       */
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
			if ( i == 0 || i == 63 || j == 0 || j == 63) // draw border
				put_pixel(&self->img, x * 64 + i, y * 64 + j, 0x0d1117);
			else
				put_pixel(&self->img, x * 64 + i, y * 64 + j, color);
		}
	}
}

t_line	get_line(int x, int y, int x1, int y1)
{
	t_line	line;

	line.x = x;
	line.y = y;
	line.x1 = x1;
	line.y1 = y1;
	return (line);
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
	if (self->player.dir > PI)
		self->player.dir_x = -1;
	else
		self->player.dir_x = 1;
	if (self->player.dir > PI / 2 && self->player.dir < 3 * PI / 2)
		self->player.dir_y = -1;
	else
		self->player.dir_y = 1;
	line = get_line(self->player.pos_x, self->player.pos_y, \
			self->player.dx + self->player.pos_x, self->player.dy + self->player.pos_y);
	breseham(self, line, 0xFF0000);
}

float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void	draw_3d(t_cubed *self, int i)
{
	int 	j;
	float	ca;

	ca = self->player.dir - self->ray.angle;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	self->ray.dist = self->ray.dist * cos(ca);
	self->ray.height = (CUBE_SIZE * W_HEIGHT) / self->ray.dist;
	if (self->ray.height > W_HEIGHT)
		self->ray.height = W_HEIGHT;
	self->ray.start = W_HEIGHT / 2 - self->ray.height / 2;
	self->ray.end = W_HEIGHT / 2 + self->ray.height / 2;
	j = -1;
	while (++j < self->ray.start)
		put_pixel(&self->img, i, j, get_color(self->map.color_ceiling));
	j--;
	draw_wall(self, i, j);
	j = self->ray.end;
	while (++j < W_HEIGHT)
		put_pixel(&self->img, i, j, get_color(self->map.color_floor));
}

void	draw_rays(t_cubed *self)
{
	int 	i;
	// t_line	line;

	i = -1;
	// while (++i < W_WIDTH)
	self->ray.angle = self->player.dir - FOV / 2;
	// self->ray.angle = self->player.dir;
	if (self->ray.angle < 0)
		self->ray.angle += 2 * PI;
	if (self->ray.angle > 2 * PI)
		self->ray.angle -= 2 * PI;
	while (++i < 640)
	{
		init_ray(self);
		draw_3d(self, i);
		// line = get_line(self->player.pos_x, self->player.pos_y, \
				// self->ray.x, self->ray.y);
		// // printf("x: %f, y: %f, x2: %f, y2: %f\n", line.x, line.y, line.x1, line.y1);
		// breseham(self, line, 0xFF00FF);
		self->ray.angle = self->player.dir + FOV / 2 - FOV * i / W_WIDTH;
		if (self->ray.angle < 0)
			self->ray.angle += 2 * PI;
		if (self->ray.angle > 2 * PI)
			self->ray.angle -= 2 * PI;
	}
}

void	draw(t_cubed *self)
{
	int		x;
	int		y;
	int		color;

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
	// printf("player: %f, %f\n", self->player.pos_x, self->player.pos_y);
	draw_player(self);
	// self->player.dir = 192.00 * PI / 180;
	// printf("%f\n", self->player.dir * 180 / PI);
	draw_rays(self);
	// mlx_clear_window(self->mlx_ptr, self->win_ptr);
	mlx_put_image_to_window(self->mlx_ptr, self->win_ptr, self->img.img, 0, 0);
	mlx_destroy_image(self->mlx_ptr, self->img.img);
}
