/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:43:33 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/05/27 03:39:41 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *lhs, const void *rhs, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (((unsigned char *)lhs)[i] != ((unsigned char *)rhs)[i])
			return (((unsigned char *)lhs)[i] - ((unsigned char *)rhs)[i]);
		i++;
	}
	return (0);
}
