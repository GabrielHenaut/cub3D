/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:15:25 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/05/27 21:07:43 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num > 2147483647 || size > 2147483647)
		return (NULL);
	ptr = (void *)malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num);
	return (ptr);
}
