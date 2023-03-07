/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:34:08 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/23 14:34:26 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int nbr)
{
	char			*result;
	int				len;
	unsigned int	aux;

	len = 1;
	aux = nbr;
	while (aux / 10 != 0 && len++)
		aux = aux / 10;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	while (len-- != 0)
	{
		result[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}
