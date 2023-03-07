/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:32:06 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/09 19:20:31 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nbr_size(ssize_t nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
		size = 1;
	while (nbr != 0)
	{
		nbr /= 2;
		size++;
	}
	return (size);
}

char	*ft_itox(ssize_t nbr)
{
	char	*nbr_hex;
	char	*hexmap;
	int		nbr_size;

	if (nbr == 0)
		return (ft_strdup("0"));
	hexmap = "01";
	nbr_size = get_nbr_size(nbr);
	nbr_hex = malloc(nbr_size + 1);
	if (nbr_hex == NULL)
		return (NULL);
	nbr_hex[nbr_size] = '\0';
	if (nbr < 0)
		nbr_hex[0] = '-';
	while (nbr != 0 || nbr_size >= 1)
	{
		nbr_hex[--nbr_size] = hexmap[nbr % 2];
		nbr /= 2;
	}
	return (nbr_hex);
}
