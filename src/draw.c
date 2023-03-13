/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghosthologram@student.42sp.org.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:20:39 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/12 22:54:02 by ghenaut-         ###   ########.fr       */
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
			if ( i == 0 || i == 63 || j == 0 || j == 63)
				put_pixel(&self->img, x * 64 + i, y * 64 + j, 0x0d1117);
			else
				put_pixel(&self->img, x * 64 + i, y * 64 + j, color);
		}
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
			else if (self->map.map[y][x] == 'N' || self->map.map[y][x] == 'S' ||
					self->map.map[y][x] == 'E' || self->map.map[y][x] == 'W')
				color = 0x0000FF;
			else
				color = 0x000000;
			draw_block(self, x, y, color);
		}
		x = -1;
	}
	mlx_put_image_to_window(self->mlx_ptr, self->win_ptr, self->img.img, 0, 0);
	mlx_destroy_image(self->mlx_ptr, self->img.img);
}
