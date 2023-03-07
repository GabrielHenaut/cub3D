/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:15:31 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:41:29 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

static char	*clear_line(char *line)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!rtn)
		return (NULL);
	while (line[++i])
	{
		rtn[j] = line[i];
		j++;
	}
	rtn[j] = '\0';
	free(line);
	return (rtn);
}

static char	*get_line(char *line)
{
	size_t	i;
	size_t	j;
	char	*rtn;

	i = 0;
	j = -1;
	if (!line[i])
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	rtn = (char *)malloc(sizeof(char) * (i + 2));
	if (!rtn)
		return (NULL);
	while (line[++j] && line[j] != '\n')
		rtn[j] = line[j];
	if (line[j] == '\n')
	{
		rtn[j] = line[j];
		j++;
	}
	rtn[j] = '\0';
	return (rtn);
}

static char	*init_line(char *line_cache, int fd)
{
	char	*buf;
	int		read_rtn;

	buf = malloc(sizeof(char) * (100 + 1));
	if (!buf)
		return (NULL);
	read_rtn = 1;
	while (!ft_strchr(line_cache, '\n') && read_rtn != 0)
	{
		read_rtn = read(fd, buf, 100);
		if (read_rtn == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_rtn] = '\0';
		line_cache = join(line_cache, buf);
	}
	free(buf);
	return (line_cache);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_cache[1024];

	if (fd < 0 || fd > 1023)
		return (0);
	line_cache[fd] = init_line(line_cache[fd], fd);
	if (!line_cache[fd])
		return (NULL);
	line = get_line(line_cache[fd]);
	line_cache[fd] = clear_line(line_cache[fd]);
	return (line);
}
