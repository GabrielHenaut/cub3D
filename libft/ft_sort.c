/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:32:10 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/12 00:28:26 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort(int *target, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	if (left >= right)
		return ;
	i = left;
	j = right;
	pivot = target[i];
	while (1)
	{
		while (target[i] < pivot)
			i++;
		while (pivot < target[j])
			j--;
		if (i >= j)
			break ;
		swap(&target[i], &target[j]);
		i++;
		j--;
	}
	sort(target, left, i - 1);
	sort(target, j + 1, right);
}

void	quicksort(int *array, int size)
{
	sort(array, 0, size - 1);
}
