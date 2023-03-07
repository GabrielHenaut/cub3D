/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:00:23 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/05 21:14:18 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_error(char *error)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(error, 2);
    ft_putstr_fd("\n", 2);
    exit(1);
}

