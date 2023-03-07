/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:59:45 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/23 21:50:46 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define STDOUT 1
# define CONVERSIONS "csdiuxXp%"

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "../libft/libft.h"

typedef struct s_param
{
	int		precision;
	size_t	width;
	char	*str;
	size_t	str_len;
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		plus;
	size_t	placeholder_len;
	int		has_precision;
	char	specifier;
	int		error;
}	t_param;

typedef struct s_rtn_str
{
	int		size;
	char	*str;
}				t_rtn_str;

int		ft_printf(const char *fmt, ...);
int		ft_vprintf(const char *fmt, va_list args);
void	generate_rtn_str(const char *fmt, va_list args, t_rtn_str *rtn);
void	add_char(char c, t_param *param);
char	*char_to_str(int c);
void	parse_arg(char *c, va_list args, t_rtn_str *rtn);
void	add_str(char *str, t_param *param);
void	handle_conversions(char c, va_list args, t_param *param);
int		fill_width(t_param *param);
void	add_int(int nbr, t_param *param);
int		handle_zero(t_param *param);
int		fill_precision(t_param *param);
int		fill_precision_int(t_param *param);
int		fill_int_width(t_param *param);
void	add_uint(unsigned int nbr, t_param *param);
void	add_hex_upper(size_t nbr, t_param *param);
void	add_hex(size_t nbr, t_param *param);
void	add_pointer(void *nbr, t_param *param);
void	add_percent(t_param *param);

#endif