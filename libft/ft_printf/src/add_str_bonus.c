/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:03:11 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:47:22 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_flags(t_param *param)
{
	if (param->str_len < param->width)
		if (fill_width(param) < 0)
			return (-1);
	return (param->str_len);
}

void	add_str(char *str, t_param *param)
{
	param->specifier = 's';
	if (str == NULL)
		str = "(null)";
	if (param->has_precision)
		param->str = ft_substr(str, 0, param->precision);
	else
		param->str = ft_strdup(str);
	param->str_len = ft_strlen(param->str);
	handle_flags(param);
}
