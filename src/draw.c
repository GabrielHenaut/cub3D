/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghosthologram@student.42sp.org.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:20:39 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/13 18:25:12 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	find_mod(float value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

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

	// printf("x: %d, y: %d, x1: %d, y1: %d\n", x, y, x1, y1);
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
	line = get_line(self->player.pos_x, self->player.pos_y, \
			self->player.dx + self->player.pos_x, self->player.dy + self->player.pos_y);
	breseham(self, line, 0xFF0000);
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
	draw_player(self);
	// mlx_clear_window(self->mlx_ptr, self->win_ptr);
	mlx_put_image_to_window(self->mlx_ptr, self->win_ptr, self->img.img, 0, 0);
	mlx_destroy_image(self->mlx_ptr, self->img.img);
}
