/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:27:53 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:45:02 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_flags_int(t_param *param)
{
	char	*tmp;

	if (param->has_precision)
		if (fill_precision_int(param) < 0)
			return (-1);
	tmp = param->str;
	if (param->plus && tmp[0] != '-')
		param->str = ft_strjoin("+", tmp);
	else if (param->space && tmp[0] != '-')
		param->str = ft_strjoin(" ", tmp);
	param->str_len++;
	if (param->width > param->str_len)
		if (fill_int_width(param) < 0)
			return (-1);
	if ((param->plus && tmp[0] != '-') || (param->space && tmp[0] != '-'))
	{
		param->str_len++;
		free(tmp);
	}
	return (param->str_len);
}

void	add_int(int nbr, t_param *param)
{
	char	*tmp;
	char	*nbr_str;

	param->specifier = 'i';
	if (param->has_precision)
		param->zero = 0;
	tmp = param->str;
	nbr_str = ft_itoa(nbr);
	param->str = ft_memjoin(tmp, param->str_len, \
	nbr_str, ft_strlen(nbr_str) + 1);
	param->str_len += ft_strlen(param->str) - 1;
	free(tmp);
	free(nbr_str);
	if (handle_flags_int(param) == -1)
		param->error = 1;
}
