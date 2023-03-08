/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghosthologram@student.42sp.org.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:03:37 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/07 23:16:22 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void print_map(t_cubed *data)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	printf("Height: %ld\tWidth: %ld\n", data->map.height, data->map.width);
	while (i < data->map.height)
	{
		while (j < data->map.width)
		{
			printf("%c", data->map.map[i][j]);
			j++;
		}
		// printf("\n");
		j = 0;
		i++;
	}
}
