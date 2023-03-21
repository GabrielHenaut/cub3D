/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:22:29 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/21 04:16:27 by harndt           ###   ########.fr       */
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
# define P2 PI/2
# define P3 3*PI/2
# define FOV  3.141592653589793238 / 3
# define SCALE_FACTOR 20

// =============================================================================
// KEY MACROS
// =============================================================================

# define DESTROY 17
# define DESTROYMASK 0L
# define KEYPRESS 2
# define KEYPRESSMASK 1
# define KEYRELEASE 3
// # define KEYRELEASEMASK 1L << 1
# define REFOCUS 07

// =============================================================================
// WINDOW SIZE
// =============================================================================

# define W_NAME "CUB3D - ghenaut- & harndt"
# define W_HEIGHT	640
# define W_WIDTH	640 //1260
# define CUBE_SIZE 64

// =============================================================================
// MESSAGE MACROS
// =============================================================================

# define STR_ERR_MALLOC "%s error: Could not allocate memory.\n"
# define STR_FILE_NOT_FOUND "%s file not found %s.\n"
# define STR_INVALID_MAP "%s invalid map extension %s.\n"
# define STR_MAP_EMPTY "%s map file is empty\n"
# define STR_PROG_NAME "cub3D:"
# define STR_USAGE "%s usage: ./cub3D <map_address>\n"
# define STR_MLX "%s Failed to initiate mlx.\n"
# define STR_WIN "%s Failed to initiate windows.\n"

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
	int		img_width;
	int		img_height;
	void	*img;
	int		*data;
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
	int		dir_x;
	int		dir_y;
}	t_player;

typedef struct s_ray
{
	float		angle;
	float		step_x;
	float		step_y;
	int			map_x;
	int			map_y;
	float		length;
	float		x;
	float		y;
	float		height;
	int			start;
	int			end;
	float		dof;
	float		h_x;
	float		h_y;
	float		v_x;
	float		v_y;
	float		dist_h;
	float		dist_v;
	float		dist;
	int			color;
	int			texture[4][4096];
	int			hit;
}	t_ray;

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
	t_ray		ray;
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
	NO,
	SO,
	EA,
	WE
};

// =============================================================================
// BRENHAM FUNCTIONS
// =============================================================================

void			breseham(t_cubed *self, t_line line, int color);
void			put_pixel(t_img *img, int x, int y, int color);

// =============================================================================
// DEBUG FUNCTION
// =============================================================================

void			print_map(t_cubed *data);

// =============================================================================
// DRAW FUNCTION
// =============================================================================

float			distance(float x1, float y1, float x2, float y2);
void			draw(t_cubed *self);
void			draw_block(t_cubed *self, int x, int y, int color);
void			draw_player(t_cubed *self);
void			draw_rays(t_cubed *self);
void			draw_3d(t_cubed *self, int i);
t_line			get_line(int x, int y, int x1, int y1);

// =============================================================================
// EXIT FUNCTIONS
// =============================================================================

int				end_program(t_cubed *self);
void			exit_error(char *error);
int				msg(char *str, char *detail, int exit_nb);

// =============================================================================
// FREE FUNCTIONS
// =============================================================================

void			free_data(t_cubed *data);
void			free_found(t_cubed *data, t_founds found, int fd);
void			free_textures(t_cubed *self);

// =============================================================================
// GET MAP FUNCTIONS
// =============================================================================

void			build_map_matrix(t_cubed *data, int fd);
void			find_map_width(t_cubed *data, int fd);
void			get_map(t_cubed *data, char *map_path);
char			*next_line(char *line, int fd);
char			*skip_to_map(int fd);

// =============================================================================
// GET TEXTURE PATH FUNCTION
// =============================================================================

void			check_line(t_cubed *data, char *line, t_founds *found);
void			check_textures(t_cubed *data, t_founds found, int fd);
char			*get_parameter(char *line, int *found);
void			get_textures_path(t_cubed *data, int fd);
int				only_valid_chars(char *line);

// =============================================================================
// HOOKS KEY
// =============================================================================

void			move_player(t_cubed *self, int dir);
int				press_key(int keysym, t_cubed *self);
void			rotate_player(t_cubed *self, int dir);
void			set_hooks(t_cubed *self);

// =============================================================================
// IMAGE FUNCTIONS
// =============================================================================

unsigned long	get_color(char *str);
void			init_img(t_img *img, t_cubed *data);

// =============================================================================
// INIT DATA FUNCTIONS
// =============================================================================

void			init_player(t_cubed *data);
void			init_map(t_cubed *data, char *map_path);
void			init_game(t_cubed *data, char *map_path);

// =============================================================================
// INIT FOUND FUNCTIONS
// =============================================================================

void			init_found(t_founds *found);

// =============================================================================
// INIT MLX FUNCTIONS
// =============================================================================

void			init_mlx(t_cubed *self);

// =============================================================================
// INIT RAY FUNCTIONS
// =============================================================================

void			init_ray(t_cubed *self);

// =============================================================================
// VALIDATE MAP FUNCTIONS
// =============================================================================

int				validate_map(t_cubed *data);

// =============================================================================
// GET TEXTURES
// =============================================================================

void	get_textures(t_cubed *self);

// =============================================================================
// DRAW WALLS
// =============================================================================

void	draw_wall(t_cubed *self, int i, int j);

#endif
