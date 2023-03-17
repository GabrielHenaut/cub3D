/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_found.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:53 by harndt            #+#    #+#             */
/*   Updated: 2023/03/17 18:29:11 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_found(t_founds *found)
{
	found->north = 0;
	found->south = 0;
	found->west = 0;
	found->east = 0;
	found->floor = 0;
	found->ceiling = 0;
	found->invalid_map = 0;
}
