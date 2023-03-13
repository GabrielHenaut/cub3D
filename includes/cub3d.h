/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:22:29 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/13 16:03:06 by ghenaut-         ###   ########.fr       */
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
# include <mlx.h>		// mlx
# include <stddef.h>
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free
# include <string.h>	// strerror
# include <unistd.h>	// write, exit
// # include <X11/keysym.h>
// # include <X11/X.h>

// =============================================================================
// LOCAL LIBRARIES
// =============================================================================

# include "keys.h"
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
// PI
// =============================================================================

# define PI 3.14159265358979323846
# define SCALE_FACTOR 9

// =============================================================================
// KEY MACROS
// =============================================================================

# define DESTROY 17
# define DESTROYMASK 0L
# define KEYPRESS 2
# define KEYPRESSMASK 1
# define KEYRELEASE 3
# define KEYRELEASEMASK 1L << 1
# define REFOCUS 07

// =============================================================================
// WINDOW SIZE
// =============================================================================

# define W_NAME "CUB3D - ghenaut- & harndt"
# define W_HEIGHT	640
# define W_WIDTH	640 //1260

// =============================================================================
// MESSAGE MACROS
// =============================================================================

# define STR_ERR_MALLOC "%s error: Could not allocate memory.\n"
# define STR_FILE_NOT_FOUND "%s file not found %s.\n"
# define STR_INVALID_MAP "%s invalid map extension %s.\n"
# define STR_MAP_EMPTY "%s map file is empty\n"
# define STR_PROG_NAME "cub3D:"
# define STR_USAGE "%s usage: ./cub3D <map_address>\n"

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
	char	**map;
	size_t	width;
	size_t	height;
	char	*texture_paths[4];
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
	int		pos_array_x;
	int		pos_array_y;
	float	dir;
	int		dx;
	int		dy;
}	t_player;

/**
 * @brief Struct to store the program macro configurations.
 */
typedef struct s_cubed
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_map		map;
	t_player	player;
}	t_cubed;

/**
 * @brief Struct to store if the map has all params and if not, with ones to
 *  free.
 */
typedef struct s_founds
{
	int		north;
	int		south;
	int		west;
	int		east;
	int		floor;
	int		ceiling;
	int		invalid_map;
}	t_founds;

/**
 * @brief Struct to store a line
 */
typedef struct s_line
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		color;
}	t_line;

// =============================================================================
// ENUMS
// =============================================================================

enum e_directions
{
	EA,
	NO,
	SO,
	WE
};

// =============================================================================
// EXIT FUNCTIONS
// =============================================================================

int		end_program(t_cubed *self);
void	exit_error(char *error);
void	free_found(t_cubed *data, t_founds found, int fd);
int		msg(char *str, char *detail, int exit_nb);
void	free_data(t_cubed *data);
void	free_textures(t_cubed *self);

// =============================================================================
// INIT FUNCTION
// =============================================================================

void	init_game(t_cubed *data, char *map_path);

// =============================================================================
// GET TEXTURE PATH FUNCTION
// =============================================================================

void	get_textures_path(t_cubed *data, int fd);

// =============================================================================
// GET MAP FUNCTIONS
// =============================================================================

void	get_map(t_cubed *data, char *map_path);

// =============================================================================
// VALIDATE MAP FUNCTIONS
// =============================================================================

int		validate_map(t_cubed *data);

// =============================================================================
// INIT MLX FUNCTIONS
// =============================================================================

void	init_mlx(t_cubed *self);

// =============================================================================
// HOOKS KEY
// =============================================================================

int		press_key(int keysym, t_cubed *self);
void	set_hooks(t_cubed *self);

// =============================================================================
// RENDER FUNCTIONS
// =============================================================================

void	draw(t_cubed *self);

// =============================================================================
// DEBUG FUNCTIONS (REMOVE BEFORE SUBMIT)
// =============================================================================

void	print_map(t_cubed *data);

#endif
