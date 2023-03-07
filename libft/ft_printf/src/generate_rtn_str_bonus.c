/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_rtn_str_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:42:33 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:52:35 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	append_to_str(t_rtn_str *rtn, char c)
{
	char	*tmp;
	char	*str;

	tmp = char_to_str(c);
	if (!tmp)
		return ;
	str = ft_memjoin(rtn->str, rtn->size, tmp, 2);
	if (!str)
		return ;
	rtn->size++;
	free(rtn->str);
	rtn->str = str;
	free(tmp);
}

void	generate_rtn_str(const char *fmt, va_list args, t_rtn_str *rtn)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			parse_arg((char *)fmt, args, rtn);
			while (!(ft_strchr(CONVERSIONS, *fmt)))
				fmt++;
		}
		else
			append_to_str(rtn, *fmt);
		fmt++;
	}
}
