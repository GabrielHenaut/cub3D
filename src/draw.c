/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:20:39 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/16 00:02:06 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Function to input pixels on the screen.
 * 
 * @param img Address to the image structure.
 * @param x Position on x axys.
 * @param y Position on y axys.
 * @param color Color to paint the pixel.
 */
static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	init_img(t_img *img, t_cubed *data)
{
	img->img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
			&img->line_length, &img->endian);
}

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

/**
 * @brief Calculates the mod form the given number.
 * 
 * @param value Value to calculate mod.
 * @return int Mod value;
 */
int	find_mod(float value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

/**
 * @brief Compares and found the larger value.
 * 
 * @param a First value to be compared.
 * @param b Second value to be compared.
 * @return int The larger value.
 */
int	find_max(float a, float b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

void	breseham(t_cubed *self, t_line line, int color)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = line.x1 - line.x;
	y_step = line.y1 - line.y;
	max = find_max(find_mod(x_step), find_mod(y_step));
	x_step /= max;
	y_step /= max;
	while (((int)(line.x - line.x1)) || ((int)(line.y - line.y1)))
	{
		put_pixel(&self->img, line.x, line.y, color);
		line.x += x_step;
		line.y += y_step;
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

void init_ray(t_cubed *self, int i)
{
	float	arc_tan;

	arc_tan = 1 / tan(self->player.dir);
	self->ray.angle = self->player.dir; 
	self->ray.dof = 0;
	// self->ray.angle = self->player.dir - (FOV / 2) + (i * FOV / 6);
	self->ray.map_x = self->player.pos_array_x;
	self->ray.map_y = self->player.pos_array_y;
	if (self->ray.angle < PI)
	{
		self->ray.y = ((int)self->player.pos_y / 64) * 64 - 0.0001;
		self->ray.x = (self->player.pos_y - self->ray.y) * arc_tan + self->player.pos_x;
		self->ray.step_y = -64;
		self->ray.step_x = -self->ray.step_y * arc_tan;
	}
	else if (self->ray.angle > PI)
	{
		self->ray.y = ((int)self->player.pos_y / 64) * 64 + 64;
		self->ray.x = (self->player.pos_y - self->ray.y) * arc_tan + self->player.pos_x;
		self->ray.step_y = 64;
		self->ray.step_x = -self->ray.step_y * arc_tan;
	}
	if (self->ray.angle == 0 || self->ray.angle == PI)
	{
		self->ray.x = self->player.pos_x;
		self->ray.y = self->player.pos_y;
		self->ray.dof = self->map.height * self->map.width;
	}
	while (self->ray.dof < 8)
	// while (self->ray.dof < self->map.height * self->map.width)
	{
		self->ray.map_x = (int)self->ray.x / 64;
		if (self->ray.map_x >= self->map.width)
			self->ray.map_x = self->map.width - 1;
		if (self->ray.map_x < 0)
			self->ray.map_x = 0;
		self->ray.map_y = (int)self->ray.y / 64;
		if (self->ray.map_y >= self->map.height)
			self->ray.map_y = self->map.height - 1;
		if (self->ray.map_y < 0)
			self->ray.map_y = 0;
		if (self->map.map[self->ray.map_y][self->ray.map_x] == '1')
			break ;
		self->ray.x += self->ray.step_x;
		self->ray.y += self->ray.step_y;
		self->ray.dof++;
	}
	// if (self->ray.angle > PI / 2 && self->ray.angle < 3 * PI / 2)
	// {
		// self->ray.ray_diry = -1;
		// self->ray.length_y = (self->player.pos_y - 
				// (float)(self->ray.map_y)) * 64 * self->ray.step_y;
	// }
	// else
	// {
		// self->ray.ray_diry = 1;-
		// self->ray.length_y = ((float)(self->ray.map_y + 1) * 64 -
				// self->player.pos_y) * self->ray.step_y;
	// }
}

void 	draw_rays(t_cubed *self)
{
	int 	i;
	t_line	line;

	i = -1;
	// while (++i < W_WIDTH)
	while (++i < 1)
	{
		init_ray(self, i);
		// calculate_ray(self);
		// draw_wall(self, i);
		line = get_line(self->player.pos_x, self->player.pos_y, \
				self->ray.x, self->ray.y);
		breseham(self, line, 0xFF00FF);
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
	// self->player.dir = 165.00 * PI / 180;
	printf("%f\n", self->player.dir * 180 / PI);
	draw_rays(self);
	// mlx_clear_window(self->mlx_ptr, self->win_ptr);
	mlx_put_image_to_window(self->mlx_ptr, self->win_ptr, self->img.img, 0, 0);
	mlx_destroy_image(self->mlx_ptr, self->img.img);
}
