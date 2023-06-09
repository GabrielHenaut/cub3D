/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:00:23 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/30 22:20:16 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
 * @param exit_nb Exit number.
 * @return int 0 to indicate failure.
 */
int	msg(char *str, char *detail, int exit_nb)
{
	if (!detail)
		printf("%s %s\n", STR_PROG_NAME, str);
	else
		printf("%s %s %s\n", STR_PROG_NAME, str, detail);
	return (exit_nb);
}

/**
 * @brief Prints error message and exits program.
 * 
 * @param error The error to print.
 */
void	exit_error(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
