/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:38:08 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/31 22:00:21 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Reads the next line.
 * 
 * @param line Pointer to the line to read.
 * @param fd Map file descriptor ID.
 * @return char* Pointer to the next line.
 */
char	*next_line(char *line, int fd)
{
	free(line);
	return (get_next_line(fd));
}

/**
 * @brief Skips to the map rows in the map file.
 * 
 * @param fd Map file descriptor ID.
 * @return char* Line where the map starts.
 */
char	*skip_to_map(int fd)
{
	char	*line;
	int		counter;
	char	c;

	line = get_next_line(fd);
	counter = 0;
	while (counter < 6)
	{
		c = line[0];
		if (c == 'N' || c == 'S' || c == 'W' || \
			c == 'E' || c == 'F' || c == 'C')
			counter++;
		line = next_line(line, fd);
	}
	line = next_line(line, fd);
	while (line[0] == '\n')
		line = next_line(line, fd);
	return (line);
}

/**
 * @brief Set the line object
 * 
 * @param data Address to the program struct.
 * @param line Address to the readed line.
 * @param i Column array index.
 * @param j Row array index.
 */
static void	set_line(t_cubed *data, char *line, int i, int j)
{
	if (j < (int)ft_strlen(line) - 1 || (i + 1 == (int)data->map.height && \
				j < (int)ft_strlen(line)))
	{
		if (line[j] == '\n')
			data->map.map[i][j] = ' ';
		else
			data->map.map[i][j] = line[j];
	}
	else
		data->map.map[i][j] = ' ';
}

/**
 * @brief Copys the map file into a matrix.
 * 
 * @param data Addres to the program structure.
 * @param fd Map file descriptor ID.
 */
void	build_map_matrix(t_cubed *data, int fd)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = -1;
	line = skip_to_map(fd);
	data->map.map = (char **)ft_calloc(sizeof(char *), data->map.height);
	if (data->map.map == NULL)
		exit_error("Error allocating memory");
	while (line && ++i < data->map.height)
	{
		data->map.map[i] = (char *)ft_calloc(sizeof(char), data->map.width);
		if (data->map.map[i] == NULL)
			exit_error("Error allocating memory");
		j = -1;
		while (++j < data->map.width)
			set_line(data, line, i, j);
		if (i + 1 < data->map.height)
			data->map.map[i][data->map.width - 1] = '\n';
		line = next_line(line, fd);
	}
	free(line);
}

/**
 * @brief Get the map object.
 * 
 * @param data Address to the program structure.
 * @param map_path Path to the map file.
 */
void	get_map(t_cubed *data, char *map_path)
{
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_error("Error opening .cub file");
	find_map_width(data, fd);
	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_error("Error opening .cub file");
	build_map_matrix(data, fd);
	close(fd);
}
