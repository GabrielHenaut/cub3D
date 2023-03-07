/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:42:28 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:49:45 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vprintf(const char *fmt, va_list args)
{
	t_rtn_str	rtn;

	rtn.str = ft_strdup("");
	rtn.size = 0;
	generate_rtn_str(fmt, args, &rtn);
	write(STDOUT, rtn.str, rtn.size);
	free(rtn.str);
	return (rtn.size);
}
