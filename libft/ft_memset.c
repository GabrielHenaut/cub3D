/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:40:26 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/01 04:08:33 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)dest)[i] = (unsigned char)ch;
		i++;
	}
	return (dest);
}
