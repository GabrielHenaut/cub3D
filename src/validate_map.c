/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghosthologram@student.42sp.org.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:13:27 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/08 22:08:09 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_letter(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

int		validate_map(t_cubed *data)
{
	size_t	i;
	size_t	j;
	int 	inside_map;
	int 	counter;

	i = -1;
	inside_map = FALSE;
	counter = 0;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			if (data->map.map[i][j] == ' ' && inside_map == TRUE)
				if (data->map.map[i][j - 1] != '1')
					return (1);
			if (data->map.map[i][j] == ' ' && inside_map == FALSE)
				if (data->map.map[i][j + 1] != '1' 
					&& data->map.map[i][j + 1] != ' ' 
					&& data->map.map[i][j + 1] != '\n')
					return (1);
			if (data->map.map[i][j] == '1' && inside_map == FALSE)
				inside_map = TRUE;
			if (data->map.map[i][j] == ' ')
				inside_map = FALSE;
			if (is_letter(data->map.map[i][j]) && counter > 0)
				return (1);
			if (is_letter(data->map.map[i][j]))
				counter++;
		}
		inside_map = FALSE;
	}
	return (0);
}
