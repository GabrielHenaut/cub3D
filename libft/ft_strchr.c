/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:33:43 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/01 23:25:32 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*return_str;

	i = 0;
	if (!str)
		return (0);
	return_str = (char *)str;
	while (str[i])
	{
		if (((char)ch) == str[i])
			return (return_str + i);
		i++;
	}
	if (((char)ch) == '\0')
		return (return_str + i);
	return (NULL);
}
