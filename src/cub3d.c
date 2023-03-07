/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:52:55 by ghenaut-          #+#    #+#             */
/*   Updated: 2023/03/06 15:35:19 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_valid_file_extension(char *str)
{
	size_t	offset;

	offset = ft_strlen(str) - 4;
	if (ft_strncmp(".cub", str + offset, 5) == 0)
		return (1);
	return (0);
}

static int	check_error(int argc, char **argv)
{
	int		printed;
	int		fd;
	char	*buff;

	printed = 0;
	buff = (char *)malloc(2 + 1);
	if (buff == NULL)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		printed = ft_printf("Error\nInvalid number of arguments\n");
	else if (!is_valid_file_extension(argv[1]))
		printed = ft_printf("Error\nInvalid file extension\n");
	else if (read(fd, buff, 0) < 0)
		printed = ft_printf("Error\nInvalid map path\n");
	else if (read(fd, buff, 2) == 0)
		printed = ft_printf("Error\nMap empty or with not at least 1 new line\n");
	free(buff);
	if (printed)
	{
		exit(1);
		return (1);
	}
	return (0);
}

// static int	rerender(t_fdf *data)
// {
	// mlx_clear_window(data->mlx, data->win);
	// draw(data);
	// return (0);
// }

int	main(int argc, char **argv)
{
	t_cubed     data;

	if (check_error(argc, argv) == 1)
		return (1);
	init_game(&data, argv[1]);
	// mlx_hook(data.win, KEYPRESS, KEYPRESSMASK, arrows_down, &data);
	// mlx_hook(data.win, REFOCUS, (1L << 04), rerender, &data);
	// mlx_hook(data.win, DESTROY, DESTROYMASK, clean_exit, &data);
	// mlx_loop(data.mlx);
	printf("%s", data.map.tex_path_east);
}
