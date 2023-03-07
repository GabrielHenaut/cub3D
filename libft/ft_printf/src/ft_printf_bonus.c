/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:10:09 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:48:43 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		rtn;
	va_list	args;

	va_start(args, fmt);
	rtn = ft_vprintf(fmt, args);
	va_end(args);
	return (rtn);
}
