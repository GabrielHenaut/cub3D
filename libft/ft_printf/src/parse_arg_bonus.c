/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:52:35 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:52:04 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_param(t_param *param)
{
	param->precision = 0;
	param->width = 0;
	param->str = NULL;
	param->str_len = 0;
	param->minus = 0;
	param->zero = 0;
	param->hash = 0;
	param->space = 0;
	param->plus = 0;
	param->placeholder_len = 0;
	param->has_precision = 0;
	param->specifier = 0;
	param->error = 0;
}

static void	ft_parse_precision(char *str, va_list args, t_param *param)
{
	int	specified;

	specified = 0;
	param->has_precision = 1;
	while (!ft_strchr(CONVERSIONS, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !specified)
		{
			if (*str == '*')
				param->precision = va_arg(args, int);
			else
				param->precision = ft_atoi(str);
			specified = 1;
		}
		str++;
	}
	if (specified == 0)
		param->precision = 0;
}

static void	parse_flags(char *str, va_list args, t_param *param)
{
	int	specified;

	specified = 0;
	while (*str != '.' && !ft_strchr(CONVERSIONS, *str))
	{
		if (*str == '-')
			param->minus = 1;
		if (*str == '+')
			param->plus = 1;
		if (*str == ' ')
			param->space = 1;
		if (*str == '#')
			param->hash = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			param->zero = 1;
		else if (((*str > '0' && *str <= '9') || *str == '*') && !specified)
		{
			if (*str == '*')
				param->width = va_arg(args, int);
			else
				param->width = ft_atoi(str);
			specified = 1;
		}
		str++;
	}
}

void	parse_arg(char *str, va_list args, t_rtn_str *rtn)
{
	t_param	param;
	char	*tmp;

	init_param(&param);
	parse_flags(str, args, &param);
	if (*str == '.' && !param.specifier)
	{
		param.precision = 1;
		ft_parse_precision(str++, args, &param);
		while (!ft_strchr(CONVERSIONS, *str))
			str++;
	}
	if ((int)param.width < 0)
	{
		param.minus = 1;
		param.width *= -1;
	}
	while (!ft_strchr(CONVERSIONS, *str))
			str++;
	handle_conversions(*str, args, &param);
	tmp = ft_memjoin(rtn->str, rtn->size, param.str, param.str_len);
	free(rtn->str);
	rtn->str = tmp;
	rtn->size += param.str_len;
	free(param.str);
}
