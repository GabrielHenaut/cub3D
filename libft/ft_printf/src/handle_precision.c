/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:49:13 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/01 16:17:49 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_precision_int(t_param *param)
{
	int		i;
	int		str_len;
	char	*new_str;
	int		is_neg;

	if (param->precision == 0)
		return (handle_zero(param));
	is_neg = param->str[0] == '-';
	str_len = ft_strlen(param->str);
	if (str_len >= param->precision + is_neg)
		return (str_len);
	new_str = malloc(param->precision + is_neg + 1);
	if (new_str == NULL)
		return (-1);
	i = 0;
	if (is_neg)
		new_str[i] = '-';
	while (i < param->precision - str_len + is_neg)
		new_str[i++ + is_neg] = '0';
	new_str[i + is_neg] = '\0';
	ft_strlcat(new_str, param->str + is_neg, param->precision + 1 + is_neg);
	free(param->str);
	param->str = new_str;
	param->str_len = param->precision + is_neg - 1;
	return (param->precision);
}

int	fill_precision(t_param *param)
{
	int		i;
	int		str_len;
	char	*new_str;

	if (param->precision == 0)
		return (handle_zero(param));
	str_len = ft_strlen(param->str);
	if (str_len >= param->precision)
		return (str_len);
	new_str = malloc(param->precision + 1);
	if (new_str == NULL)
		return (-1);
	i = 0;
	new_str[param->precision] = '\0';
	while (i < param->precision - str_len)
		new_str[i++] = '0';
	new_str[i] = '\0';
	ft_strlcat(new_str, param->str, param->precision + 1);
	free(param->str);
	param->str = new_str;
	param->str_len = param->precision;
	return (param->precision);
}
