/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:00:23 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/07 20:31:05 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		printf(str, STR_PROG_NAME);
	else
		printf(str, STR_PROG_NAME, detail);
	return (exit_nb);
}

void	exit_error(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
