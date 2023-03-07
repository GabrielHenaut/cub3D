/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:22:29 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/07 20:30:34 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// =============================================================================
// EXTERNAL LIBRARIES
// =============================================================================

# include <errno.h>		// perror
# include <fcntl.h>		// open, close, read
# include <math.h>
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free
# include <string.h>	// strerror
# include <unistd.h>	// write, exit

// =============================================================================
// LOCAL LIBRARIES
// =============================================================================

# include "../libft/libft.h"
// # include "../mlx/mlx.h"

// =============================================================================
// BOOLEAN TYPE
// =============================================================================

# define TRUE 1
# define FALSE 0

/**
 * @brief Boolean type. TRUE (1)/FALSE (0)
 */
typedef int	t_bool;

// =============================================================================
// KEY MACROS
// =============================================================================

# define DESTROY 17
# define DESTROYMASK 0L
# define KEYPRESS 2
# define KEYPRESSMASK 1
# define REFOCUS 07

// =============================================================================
// MESSAGE MACROS
// =============================================================================

# define STR_PROG_NAME "cub3D:"
# define STR_USAGE "%s usage: ./cub3D <map_address>\n"
# define STR_ERR_MALLOC "%s error: Could not allocate memory.\n"
# define STR_INVALID_MAP "%s invalid map extension %s.\n"
# define STR_FILE_NOT_FOUND "%s file not found %s.\n"
# define STR_MAP_EMPTY "%s map file is empty\n"

// =============================================================================
// STRUCTS
// =============================================================================

/**
 * @brief Struct to store the image values to be plotted on the screen.
 */
typedef struct s_img
{
	char	*addr;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
	void	*img;
}	t_img;

/**
 * @brief Struct to store the values read from the map file.
 */
typedef struct s_map
{
	int		**map;
	int		width;
	int		height;
	char	*tex_path_north;
	char	*tex_path_south;
	char	*tex_path_west;
	char	*tex_path_east;
	char	*color_floor;
	char	*color_ceiling;
	int		tex_north[64][64];
	int		tex_south[64][64];
	int		tex_west[64][64];
	int		tex_east[64][64];
}	t_map;

/**
 * @brief Struct to store the player data.
 */
typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		dir_x;
	int		dir_y;
	int		plane_x;
	int		plane_y;
	float	move_speed;
	float	rot_speed;
}	t_player;

/**
 * @brief Struct to store the program macro configurations.
 */
typedef struct s_cubed
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_player	player;
}	t_cubed;

/**
 * @brief Struct to store the map background(?).
 */
typedef struct s_founds
{
	int		north;
	int		south;
	int		west;
	int		east;
	int		floor;
	int		ceiling;
}	t_founds;

// =============================================================================
// EXIT FUNCTIONS
// =============================================================================

void	exit_error(char *error);
int		msg(char *str, char *detail, int exit_nb);

// =============================================================================
// INIT FUBCTION
// =============================================================================

void	init_game(t_cubed *data, char *map_path);

// =============================================================================
// GET TEXTURE PATH FUNCTION
// =============================================================================

int		get_textures(t_cubed *data, int fd);

#endif
