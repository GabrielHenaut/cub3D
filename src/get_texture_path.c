/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghosthologram@student.42sp.org.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:30:23 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/06 21:32:54 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_found(t_cubed *data, t_founds found, int fd)
{
	if (found.north == 1)
		free(data->map.tex_path_north);
	if (found.south == 1)
		free(data->map.tex_path_south);
	if (found.west == 1)
		free(data->map.tex_path_west);
	if (found.east == 1)
		free(data->map.tex_path_east);
	if (found.floor == 1)
		free(data->map.color_floor);
	if (found.ceiling == 1)
		free(data->map.color_ceiling);
	close(fd);
	exit_error(".cub file structure incorect");
}

void	check_textures(t_cubed *data, t_founds found, int fd)
{
	if (found.north != 1 || found.south != 1 || found.west != 1 || found.east != 1)
		free_found(data, found, fd);
	if (found.floor != 1 || found.ceiling != 1)
		free_found(data, found, fd);
}

char	*get_path(char *line, int *found)
{
	char	*path;

	path = ft_strdup(line + 3);
	if (path == NULL)
		exit_error("Error allocating memory");
	*found = 1;
	return (path);
}

void	init_found(t_founds *found)
{
	found->north = 0;
	found->south = 0;
	found->west = 0;
	found->east = 0;
	found->floor = 0;
	found->ceiling = 0;
}

int	 get_textures(t_cubed *data, int fd)
{
	char		*line;
	t_founds	found;

	line = get_next_line(fd);
	init_found(&found);
	while (line)
	{
		if (ft_strncmp(line, "NO", 2) == 0)
			data->map.tex_path_north = get_path(line + 3, &found.north); 
		else if (ft_strncmp(line, "SO", 2) == 0)
			data->map.tex_path_south = get_path(line + 3, &found.south); 
		else if (ft_strncmp(line, "WE", 2) == 0)
			data->map.tex_path_west = get_path(line + 3, &found.west); 
		else if (ft_strncmp(line, "EA", 2) == 0)
			data->map.tex_path_east = get_path(line + 3, &found.east); 
		else if (ft_strncmp(line, "F", 1) == 0)
			data->map.color_floor = get_path(line + 2, &found.floor); 
		else if (ft_strncmp(line, "C", 1) == 0)
			data->map.color_ceiling = get_path(line + 2, &found.ceiling); 
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	check_textures(data, found, fd);
	return (0);
}

