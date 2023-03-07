/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:50:58 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/09 12:18:14 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
	{
		ft_putstr_fd("ERROR_IN_FT_LSTADD_FRONT\n", 1);
		return (0);
	}
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	new->next = *lst;
	*lst = new;
	return (1);
}
