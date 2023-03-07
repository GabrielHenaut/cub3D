/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:15:37 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/05/27 20:46:57 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (!s2 || !s2[0])
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[j + i] == s2[j] && i + j < n && s1[i + j] && s2[j])
			j++;
		if (s2[j] == '\0')
			return (&((char *)s1)[i]);
		i++;
	}
	return (NULL);
}
