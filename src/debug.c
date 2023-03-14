/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:03:37 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/14 00:53:49 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Prints the map file received as input.
 * 
 * @param data Address to the program structure.
 */
void	print_map(t_cubed *data)
{
	size_t	i;

	i = 0;
	printf("Height: %ld\tWidth: %ld\n", data->map.height, data->map.width);
	while (i < data->map.height)
	{
		printf("%s", data->map.map[i]);
		i++;
	}
}
