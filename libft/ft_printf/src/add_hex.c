/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:55:13 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:51:22 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_hex_width(t_param *param)
{
	size_t	i;
	char	*new_str;
	int		has_hash;

	if (param->minus || !param->zero)
		return (fill_width(param));
	new_str = malloc(param->width + 1);
	if (new_str == NULL)
		return (-1);
	has_hash = param->hash * 2;
	i = 0;
	if (has_hash)
	{
		new_str[0] = '0';
		new_str[1] = param->specifier;
	}
	while (i < param->width - param->str_len)
		new_str[i++ + has_hash] = '0';
	new_str[i + has_hash] = '\0';
	ft_strlcat(new_str, param->str + has_hash, param->width + 1);
	free(param->str);
	param->str = new_str;
	param->str_len = param->width;
	return (1);
}

static int	handle_flags_hex(t_param *param)
{
	char	*tmp;

	if (param->has_precision)
		fill_precision(param);
	if (param->hash)
	{
		tmp = param->str;
		param->str = ft_strjoin("0x", tmp);
		param->str_len += 2;
		free(tmp);
	}
	if (param->width > param->str_len)
		if (fill_hex_width(param) < 0)
			return (-1);
	return (param->str_len);
}

void	add_hex(size_t nbr, t_param *param)
{
	char	*nbr_str;
	char	*tmp;

	param->specifier = 'x';
	if (param->has_precision)
		param->zero = 0;
	if (nbr == 0)
		param->hash = 0;
	tmp = param->str;
	nbr_str = ft_itox(nbr);
	param->str = ft_memjoin(tmp, param->str_len, nbr_str, \
	ft_strlen(nbr_str) + 1);
	param->str_len += ft_strlen(param->str);
	free(tmp);
	free(nbr_str);
	if (handle_flags_hex(param) == -1)
		param->error = 1;
}

void	add_hex_upper(size_t nbr, t_param *param)
{
	add_hex(nbr, param);
	param->specifier = 'X';
	ft_strtoupper(param->str);
}
