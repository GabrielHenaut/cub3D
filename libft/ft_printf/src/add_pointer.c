/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:19:15 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:47:14 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*int_to_pointer(size_t nbr)
{
	char	*hex;
	char	*address;

	if (nbr == 0)
	{
		address = ft_strdup("(nil)");
	}
	else
	{
		hex = ft_uitox(nbr);
		address = ft_strjoin("0x", hex);
		free(hex);
	}
	return (address);
}

static int	handle_flags_pointer(t_param *param)
{
	if (param->str_len < param->width)
		if (fill_width(param) < 0)
			return (-1);
	return (param->str_len);
}

void	add_pointer(void *nbr, t_param *param)
{
	char	*nbr_str;
	char	*tmp;

	param->specifier = 'p';
	tmp = param->str;
	nbr_str = int_to_pointer((size_t) nbr);
	param->str = ft_memjoin(tmp, param->str_len, nbr_str, \
						ft_strlen(nbr_str) + 1);
	param->str_len += ft_strlen(param->str);
	free(tmp);
	free(nbr_str);
	if (handle_flags_pointer(param) == -1)
		param->error = 1;
}
