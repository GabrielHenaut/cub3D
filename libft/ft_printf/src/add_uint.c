/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:21:17 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:47:48 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_flags_uint(t_param *param)
{
	if (param->has_precision)
		fill_precision(param);
	if (param->width > param->str_len)
		if (fill_int_width(param) < 0)
			return (-1);
	return (param->str_len);
}

void	add_uint(unsigned int nbr, t_param *param)
{
	char	*nbr_str;
	char	*tmp;

	param->specifier = 'u';
	if (param->has_precision)
		param->zero = 0;
	tmp = param->str;
	nbr_str = ft_uitoa(nbr);
	param->str = ft_memjoin(tmp, param->str_len, nbr_str, \
			ft_strlen(nbr_str) + 1);
	param->str_len += ft_strlen(param->str);
	free(tmp);
	free(nbr_str);
	if (handle_flags_uint(param) == -1)
		param->error = 1;
}
