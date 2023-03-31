/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:30:23 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/31 20:42:51 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Checks if the initial parameters were found.
 * 
 * @param data Address to the program struct.
 * @param found Addres to the found sruct.
 * @param fd Index to the file descriptor.
 */
void	check_textures(t_cubed *data, t_founds found, int fd)
{
	if (found.north != 1 || found.south != 1 || found.west != 1 || \
		found.east != 1)
		free_found(data, found, fd);
	if (found.floor != 1 || found.ceiling != 1)
		free_found(data, found, fd);
	if (found.invalid_map != 0)
		free_found(data, found, fd);
}

/**
 * @brief Get the address to textures directions and colors from ceiling and 
 * floor.
 * 
 * @param line The readed line.
 * @param found Int pointer.
 * @return char* The readed parameter.
 */
char	*get_parameter(char *line, int *found)
{
	char	*path;

	line = ft_strtrim(line, " ");
	// printf("%s", line);
	path = ft_strdup(line);
	if (path == NULL)
		exit_error("Error allocating memory");
	if (!*found)
		*found = 1;
	else
		*found = 0;
	path[ft_strlen(path) - 1] = '\0';
	return (path);
}

/**
 * @brief Checks if the line contains only the valid char inputs.
 * 
 * @param line Addres to the line to check.
 * @return int If the line contains only valid chars 0, else 1.
 */
int	only_valid_chars(char *line)
{
	int		i;

	i = -1;
	if (line[0] == '\n')
		return (0);
	while (line[++i])
		if (line[i] != ' ' && line[i] != '1' && line[i] != '\n' && \
				line[i] != '0' && line[i] != 'N' && \
				line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (1);
	return (0);
}

/**
 * @brief Checks parameters on map file.
 * 
 * @param data Address to the program struct.
 * @param line The readed line.
 * @param found Address to the found struct.
 */
void	check_line(t_cubed *data, char *line, t_founds *found)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		data->map.texture_paths[NO] = get_parameter(line + 3, &found->north);
	else if (ft_strncmp(line, "SO", 2) == 0)
		data->map.texture_paths[SO] = get_parameter(line + 3, &found->south);
	else if (ft_strncmp(line, "WE", 2) == 0)
		data->map.texture_paths[WE] = get_parameter(line + 3, &found->west);
	else if (ft_strncmp(line, "EA", 2) == 0)
		data->map.texture_paths[EA] = get_parameter(line + 3, &found->east);
	else if (ft_strncmp(line, "F", 1) == 0)
		data->map.color_floor = get_parameter(line + 2, &found->floor);
	else if (ft_strncmp(line, "C", 1) == 0)
		data->map.color_ceiling = get_parameter(line + 2, &found->ceiling);
	else if (only_valid_chars(line) == 1)
		found->invalid_map = 1;
}

/**
 * @brief Get the textures path from the given file.
 * 
 * @param data Address to the program structure.
 * @param fd Map file descriptor ID.
 */
void	get_textures_path(t_cubed *data, int fd)
{
	char		*line;
	t_founds	found;

	line = get_next_line(fd);
	init_found(&found);
	while (line)
	{
		check_line(data, line, &found);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	check_textures(data, found, fd);
}
