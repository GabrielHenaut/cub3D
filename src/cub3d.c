/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:52:55 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/08 19:13:36 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Checks if the map file extension is valid.
 * 
 * @param str Address to the given file.
 * @return t_bool If the file is valid TRUE, else FALSE.
 */
static t_bool	is_valid_file_extension(char *str)
{
	size_t	offset;

	offset = ft_strlen(str) - 4;
	if (ft_strncmp(".cub", str + offset, 5) == 0)
		return (TRUE);
	return (FALSE);
}

/**
 * @brief Checks if the received args by command line are correct.
 * 
 * @param argc Total number of args received by command line.
 * @param argv Args received by command line.
 * @return t_bool If arguments are valid TRUE, else FALSE. 
 */
static t_bool	check_args(int argc, char **argv)
{
	int		fd;
	char	*buff;

	if (argc != 2)
		return (msg(STR_USAGE, NULL, FALSE));
	if (!is_valid_file_extension(argv[1]))
		return (msg(STR_INVALID_MAP, argv[1], FALSE));
	buff = (char *)malloc(2 + 1);
	if (buff == NULL)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (read(fd, buff, 0) < 0)
	{
		free(buff);
		return (msg(STR_FILE_NOT_FOUND, argv[1], FALSE));
	}
	else if (read(fd, buff, 2) == 0)
	{
		free(buff);
		return (msg(STR_MAP_EMPTY, argv[1], FALSE));
	}
	free(buff);
	return (TRUE);
}

/**
 * @brief Main function, checks args received by command line and executes the
 * program.
 * 
 * @param argc Total number of args received by command line.
 * @param argv Args received by command line.
 * @return int On success returns 0, esle returns 1.
 */
int	main(int argc, char **argv)
{
	t_cubed	data;

	if (check_args(argc, argv) == 0)
		return (EXIT_FAILURE);
	init_game(&data, argv[1]);
	init_mlx(&data);
	set_hooks(&data);
	mlx_loop(data.mlx_ptr);

	return (EXIT_SUCCESS);
}
