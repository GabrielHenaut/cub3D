/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:38:08 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/14 02:14:11 by harndt           ###   ########.fr       */
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
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'F' || c == 'C')
			counter++;
		line = next_line(line, fd);
	}
	line = next_line(line, fd);
	while (line[0] == '\n')
		line = next_line(line, fd);
	return (line);
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
	j = -1;
	line = skip_to_map(fd);
	data->map.map = (char **)ft_calloc(sizeof(char *), data->map.height);
	if (data->map.map == NULL)
		exit_error("Error allocating memory");
	while (line && ++i < data->map.height)
	{
		data->map.map[i] = (char *)ft_calloc(sizeof(char), data->map.width);
		if (data->map.map[i] == NULL)
			exit_error("Error allocating memory");
		while (++j < data->map.width)
		{
			if (j < ft_strlen(line) - 1 || (i + 1 == data->map.height && j < ft_strlen(line)))
				data->map.map[i][j] = line[j];
			else
				data->map.map[i][j] = ' ';
		}
		if (i + 1 < data->map.height)
			data->map.map[i][j - 1] = '\n';
		j = -1;
		line = next_line(line, fd);
	}
	free(line);
}

/**
 * @brief Finds the map width.
 * 
 * @param data Addres to the program structure.
 * @param fd Map file descriptor ID.
 */
void	find_map_width(t_cubed *data, int fd)
{
	char	*line;

	line = skip_to_map(fd);
	while (line && ++data->map.height)
	{
		if (ft_strlen(line) > data->map.width)
			data->map.width = ft_strlen(line);
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
