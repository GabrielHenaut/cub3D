/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:22:03 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/11 00:22:39 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_size(size_t size, size_t start, size_t max_len)
{
	unsigned int	tmp;

	if (start < size)
		tmp = size - start;
	if (start >= size)
		tmp = 0;
	if (tmp > max_len)
		tmp = max_len;
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	sub_str_size;
	size_t			size;

	if (!s)
		return (NULL);
	size = (unsigned int) ft_strlen(s);
	sub_str_size = ft_size(size, start, len);
	if (sub_str_size == 0)
		return (ft_strdup(""));
	sub_str = ft_calloc(sub_str_size + 1, sizeof(char));
	if (!sub_str)
		return (NULL);
	ft_strlcpy (sub_str, &s[start], sub_str_size + 1);
	return (sub_str);
}
