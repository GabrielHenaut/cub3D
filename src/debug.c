/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghosthologram@student.42sp.org.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:03:37 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/08 22:41:39 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void print_map(t_cubed *data)
{
	size_t i;

	i = 0;
	printf("Height: %ld\tWidth: %ld\n", data->map.height, data->map.width);
	while (i < data->map.height)
	{
		printf("%s", data->map.map[i]);
		i++;
	}
}
