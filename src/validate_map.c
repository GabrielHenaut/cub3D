/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:13:27 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/14 19:05:05 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Checks if the given parameter is a letter.
 * 
 * @param c Char to check.
 * @return int TRUE when the char is N/S/E/W, else FALSE.
 */
int	is_letter(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

/**
 * @brief Validates the map map file.
 * 
 * @param data Address to the program struct.
 * @return int 
 */
int	validate_map(t_cubed *data)
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
