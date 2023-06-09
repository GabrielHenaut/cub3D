/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:13:27 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/04/01 03:42:41 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Checks if the given parameter is a letter.
 * 
 * @param c Char to check.
 * @return int TRUE when the char is N/S/E/W, else FALSE.
 */
static int	is_letter(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

/**
 * @brief Check the values inside the map.
 * 
 * @param data Address to the program struct.
 * @param inside_map Int to tell if is inside or not in the map.
 * @param i Column array index.
 * @param j Row array index.
 * @return int If outside the map 1, else 0.
 */
static int	check_inside_map_line(t_cubed *data, int *inside_map, int i, int j)
{
	if (i == (int)data->map.height - 1)
		return (0);
	if (data->map.map[i][j] == ' ' && *inside_map == TRUE)
		if (data->map.map[i][j - 1] != '1')
			return (1);
	if (data->map.map[i][j] == ' ' && *inside_map == FALSE)
		if (data->map.map[i][j + 1] != '1' && \
			data->map.map[i][j + 1] != ' ' && \
			data->map.map[i][j + 1] != '\n')
			return (1);
	if (data->map.map[i][j] == '1' && *inside_map == FALSE)
		*inside_map = TRUE;
	if (data->map.map[i][j] == ' ')
		*inside_map = FALSE;
	if (data->map.map[i][j] == '0' && *inside_map == FALSE)
		return (1);
	if (data->map.map[i][j] == '0' && *inside_map == TRUE && \
		j == (int)data->map.width - 2)
		return (1);
	return (0);
}

/**
 * @brief Check the values inside the map.
 * 
 * @param data Address to the program struct.
 * @param inside_map Int to tell if is inside or not in the map.
 * @param i Column array index.
 * @param j Row array index.
 * @return int If outside the map 1, else 0.
 */
static int	check_inside_map_col(t_cubed *data, int *inside_map, int i, int j)
{
	if (data->map.map[i][j] == ' ' && *inside_map == TRUE)
		if (data->map.map[i - 1][j] != '1')
			return (1);
	if (i + 1 == (int)data->map.height)
		return (0);
	if (data->map.map[i][j] == ' ' && *inside_map == FALSE)
		if (data->map.map[i + 1][j] != '1' && \
			data->map.map[i + 1][j] != ' ' && \
			data->map.map[i + 1][j] != '\n')
			return (1);
	if (data->map.map[i][j] == '1' && *inside_map == FALSE)
		*inside_map = TRUE;
	if (data->map.map[i][j] == ' ')
		*inside_map = FALSE;
	if (data->map.map[i][j] == '0' && *inside_map == FALSE)
		return (1);
	if (data->map.map[i][j] == '0' && *inside_map == TRUE && \
		i == (int)data->map.height - 1)
		return (1);
	return (0);
}

static int	check_map_vertically(t_cubed *data)
{
	size_t	i;
	size_t	j;
	int		inside_map;

	i = -1;
	while (++i < data->map.width)
	{
		j = -1;
		while (++j < data->map.height)
			if (check_inside_map_col(data, &inside_map, j, i) == 1)
				return (1);
		inside_map = FALSE;
	}
	return (0);
}

/**
 * @brief Validates the map map file.
 * 
 * @param data Address to the program struct.
 * @return int If the map is valid returns 0, else returns 1.
 */
int	validate_map(t_cubed *data)
{
	size_t	i;
	size_t	j;
	int		inside_map;
	int		counter;

	i = -1;
	inside_map = FALSE;
	counter = 0;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			if (check_inside_map_line(data, &inside_map, i, j) == 1)
				return (1);
			if (is_letter(data->map.map[i][j]) && counter > 0)
				return (1);
			if (is_letter(data->map.map[i][j]))
				counter++;
		}
		inside_map = FALSE;
	}
	if (check_map_vertically(data) == 1)
		return (1);
	return (0);
}
