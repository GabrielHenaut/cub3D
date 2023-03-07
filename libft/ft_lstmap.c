/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:46:31 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/05/27 03:36:58 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;
	t_list	*new_tmp;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	tmp = lst->next;
	new_tmp = new_lst;
	while (tmp)
	{
		new_tmp->next = ft_lstnew(f(tmp->content));
		if (!new_tmp->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_tmp = new_tmp->next;
		tmp = tmp->next;
	}
	return (new_lst);
}
