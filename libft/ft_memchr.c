/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:18:01 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/05/27 04:01:08 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	size_t			i;
	unsigned char	*return_ptr;

	i = 0;
	return_ptr = (unsigned char *)ptr;
	while (i < count)
	{
		if (((unsigned char *)ptr)[i] == ((unsigned char)ch))
			return (return_ptr + i);
		i++;
	}
	return (NULL);
}
