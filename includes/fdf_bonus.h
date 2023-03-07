/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:43:14 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/04 23:16:29 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define KEYPRESS 2
# define KEYPRESSMASK 1
# define REFOCUS 07 
# define DESTROY 17
# define DESTROYMASK 0L

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;



void	init_game(t_fdf *data, char *file);
void	free_split(char **split);
void	draw(t_fdf *data);
int		clean_exit(t_fdf *data);
int		arrows_down(int key, t_fdf *data);
void	set_isometric(t_fdf *data);
void	set_paralle(t_fdf *data);
void	isometric(t_dot *dot, t_fdf *data);
int		find_mod(float value);
int		find_max(float a, float b);
int		find_color(float z, float z1, int color);

#endif
