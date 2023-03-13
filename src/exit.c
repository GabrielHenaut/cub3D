/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:00:23 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/12 16:38:55 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Frees the allocated memmory where the diretion textures are stored.
 * 
 * @param self Address to the program struct.
 */
void	free_textures(t_cubed *self)
{
	int	i;

	i = -1;
	while (++i < 4)
			free(self->map.texture_paths[i]);
}

void	free_data(t_cubed *data)
{
	size_t	i;

	i = -1;
	while (++i < data->map.height)
			free(data->map.map[i]);
	free_textures(data);
	free(data->map.map);
	free(data->map.color_floor);
	free(data->map.color_ceiling);
}

/**
 * @brief Routine to end the program, clear window, destroy images, window and
 * display, also frees all the allocated memory.
 * 
 * @param self Address to the program struct.
 * @return int Success code.
 */
int	end_program(t_cubed *self)
{
	mlx_clear_window(self->mlx_ptr, self->win_ptr);
	mlx_destroy_window(self->mlx_ptr, self->win_ptr);
	mlx_destroy_display(self->mlx_ptr);
	mlx_loop_end(self->mlx_ptr);
	free(self->mlx_ptr);
	free_data(self);
	exit(EXIT_SUCCESS);
}


/**
 * @brief Prints a message on the terminal and frees all memory.
 * 
 * @param str The error ocurred.
 * @param detail Any relevant error details.
 * @param self A pointer to the programs config structure.
 * @return int 0 to indicate failure.
 */
int	msg(char *str, char *detail, int exit_nb)
{
	if (!detail)
		printf("%s %s", str, STR_PROG_NAME);
	else
		printf("%s %s %s", str, STR_PROG_NAME, detail);
	return (exit_nb);
}

void	free_found(t_cubed *data, t_founds found, int fd)
{
	if (found.north == 1)
		free(data->map.texture_paths[NO]);
	if (found.south == 1)
		free(data->map.texture_paths[SO]);
	if (found.west == 1)
		free(data->map.texture_paths[WE]);
	if (found.east == 1)
		free(data->map.texture_paths[EA]);
	if (found.floor == 1)
		free(data->map.color_floor);
	if (found.ceiling == 1)
		free(data->map.color_ceiling);
	close(fd);
	exit_error(".cub file structure incorect");
}

void	exit_error(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
