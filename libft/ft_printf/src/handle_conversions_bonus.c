/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:17:12 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:51:04 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_conversions(char c, va_list args, t_param *param)
{
	if (c == 'c')
		add_char(va_arg(args, int), param);
	else if (c == 's')
		add_str(va_arg(args, char *), param);
	else if (c == 'd' || c == 'i')
		add_int(va_arg(args, int), param);
	else if (c == 'u')
		add_uint(va_arg(args, unsigned int), param);
	else if (c == 'x')
		add_hex(va_arg(args, unsigned int), param);
	else if (c == 'X')
		add_hex_upper(va_arg(args, unsigned int), param);
	else if (c == 'p')
		add_pointer(va_arg(args, void *), param);
	else if (c == '%')
		add_percent(param);
	else
		param->str = NULL;
}
