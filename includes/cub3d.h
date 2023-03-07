/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghosthologram@student.42sp.org.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:22:29 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/06 20:54:41 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H 
# define CUBED_H

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

typedef struct s_map
{
    int		**map;
    int		width;
    int		height;
    char    *tex_path_north;
    char    *tex_path_south;
    char    *tex_path_west;
    char    *tex_path_east;
    int     tex_north[64][64];
    int     tex_south[64][64];
    int     tex_west[64][64];
    int     tex_east[64][64];
    char    *color_floor;
    char    *color_ceiling;
}				t_map;

typedef struct s_player
{
    int		pos_x;
    int		pos_y;
    int		dir_x;
    int		dir_y;
    int		plane_x;
    int		plane_y;
    float   move_speed;
    float   rot_speed;
}				t_player;

typedef struct s_cubed
{
    void	*mlx;
    void	*win;
    t_img	img;
    t_map	map;
    t_player	player;
}				t_cubed;

typedef struct s_founds
{
	int		north;
	int		south;
	int		west;
	int		east;
	int		floor;
	int		ceiling;
}				t_founds;

// exit.c

void	exit_error(char *error);

// init_data.c

void	init_game(t_cubed *data, char *map_path);

// get_texture_path.c

int	 get_textures(t_cubed *data, int fd);

#endif
