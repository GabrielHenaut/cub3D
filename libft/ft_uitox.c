/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:27:54 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:41:45 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nbr_size(size_t nbr, int base_size)
{
	int	nbr_size;

	nbr_size = 1;
	while (nbr / base_size > 0)
	{
		nbr /= base_size;
		nbr_size++;
	}
	return (nbr_size);
}

char	*ft_uitox(size_t nbr)
{
	int		nbr_size;
	char	*nbr_str;

	nbr_size = get_nbr_size(nbr, 16);
	nbr_str = ft_calloc(nbr_size + 1, 1);
	if (nbr_str == NULL)
		return (NULL);
	while (nbr != 0 || nbr_size >= 1)
	{
		nbr_str[--nbr_size] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
	}
	return (nbr_str);
}
