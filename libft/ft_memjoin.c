/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:19:07 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/21 17:19:24 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *s1, size_t s1_size, void *s2, size_t s2_size)
{
	void	*new_block;
	size_t	new_size;

	new_size = s1_size + s2_size;
	new_block = malloc(new_size);
	if (new_block == NULL)
		return (NULL);
	ft_memcpy(new_block, s1, s1_size);
	ft_memcpy(new_block + s1_size, s2, s2_size);
	return (new_block);
}
