/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:00:23 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/07 19:16:14 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		free(data->map.tex_path_north);
	if (found.south == 1)
		free(data->map.tex_path_south);
	if (found.west == 1)
		free(data->map.tex_path_west);
	if (found.east == 1)
		free(data->map.tex_path_east);
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
