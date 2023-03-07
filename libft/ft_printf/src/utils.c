/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:22:41 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:51:36 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_width(t_param *param)
{
	char	*new_str;
	int		i;

	new_str = malloc(param->width + 1);
	if (new_str == NULL)
		return (-1);
	i = 0;
	if (!param->minus)
		while (i < (int)(param->width - param->str_len))
			new_str[i++] = ' ';
	new_str[i] = '\0';
	ft_strlcat(new_str, param->str, param->width + 1);
	i = param->str_len;
	if (param->minus)
	{
		while (i < (int)(param->width))
			new_str[i++] = ' ';
		new_str[i] = '\0';
	}
	free(param->str);
	param->str = new_str;
	param->str_len = param->width;
	return (1);
}

char	*char_to_str(int c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = (char)c;
	return (str);
}

int	handle_zero(t_param *param)
{
	if (param->str[0] == '0')
	{
		free(param->str);
		param->str = ft_strdup("");
		param->str_len = 0;
	}
	return (param->precision);
}

int	fill_int_width(t_param *param)
{
	size_t	i;
	char	*new_str;
	int		prefix;
	int		has_prefix;

	if (param->minus || !param->zero)
		return (fill_width(param));
	new_str = malloc(param->width + 1);
	if (new_str == NULL)
		return (-1);
	has_prefix = !ft_isdigit(param->str[0]);
	prefix = param->str[0];
	i = 0;
	if (has_prefix)
		new_str[0] = prefix;
	while (i < param->width - param->str_len)
		new_str[i++ + has_prefix] = '0';
	new_str[i + has_prefix] = '\0';
	ft_strlcat(new_str, param->str + has_prefix, param->width + 1);
	free(param->str);
	param->str = new_str;
	param->str_len = param->width;
	return (1);
}
