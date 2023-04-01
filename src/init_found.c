/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_found.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:53 by harndt            #+#    #+#             */
/*   Updated: 2023/04/01 03:40:24 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Initiates the found struct.
 * 
 * @param found Address to the found struct.
 */
void	init_found(t_founds *found)
{
	found->north = 0;
	found->south = 0;
	found->west = 0;
	found->east = 0;
	found->floor = 0;
	found->ceiling = 0;
	found->invalid_map = 0;
	found->map = 0;
}
