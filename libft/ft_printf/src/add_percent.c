/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:52:46 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/07 22:45:48 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_percent(t_param *param)
{
	char	*str;
	char	*tmp;

	param->specifier = '%';
	tmp = param->str;
	str = ft_strdup("%");
	param->str = ft_memjoin(tmp, param->str_len, str, ft_strlen(str) + 1);
	param->str_len += ft_strlen(param->str);
	free(tmp);
	free(str);
}
