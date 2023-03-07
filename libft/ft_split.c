/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:29:10 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/05/27 20:09:55 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_size(const char *s, char c)
{
	int	size;
	int	pos;

	size = 0;
	pos = 0;
	while (*s && *s == c)
		s++;
	while (s[pos])
	{
		if (!pos)
			size++;
		else if (s[pos - 1] == c && s[pos] != c)
			size++;
		pos++;
	}
	return (size);
}

static size_t	word_position(char const *s, char c)
{
	size_t	pos;

	pos = 0;
	while (s[pos] && s[pos] != c)
		pos++;
	return (pos);
}

char	**ft_split(char const *s, char c)
{
	char	**return_str;
	size_t	word_len;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = check_size(s, c);
	return_str = malloc(sizeof(char *) * (size + 1));
	if (!return_str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*s && *s == c)
			s++;
		word_len = word_position(s, c);
		return_str[i] = ft_substr(s, 0, word_len);
		s += word_len + 1;
		i++;
	}
	return_str[size] = NULL;
	return (return_str);
}
