/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:47:34 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:45:56 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_char_width(t_param *param)
{
	char	*new_str;
	size_t	i;

	new_str = malloc(param->width + 1);
	if (!new_str)
		return (-1);
	i = 0;
	if (!param->minus)
		while (i < param->width - 1)
			new_str[i++] = ' ';
	new_str[i] = param->str[0];
	if (param->minus)
	{
		while (++i < param->width)
			new_str[i] = ' ';
		new_str[i] = '\0';
	}
	free(param->str);
	param->str = new_str;
	param->str_len = param->width;
	return (1);
}

static int	handle_flags(t_param *param)
{
	param->str_len = 1;
	if (param->width > 1)
		if (fill_char_width(param) < 0)
			return (-1);
	return (param->str_len);
}

void	add_char(char c, t_param *param)
{
	param->specifier = 'c';
	param->str = char_to_str(c);
	if (handle_flags(param) == -1)
		param->error = 1;
}
