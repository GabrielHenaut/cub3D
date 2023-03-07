/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:33:51 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/02 00:31:43 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	if (dest > src)
	{
		i = (int)count - 1;
		while (i >= 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < (int)count)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
