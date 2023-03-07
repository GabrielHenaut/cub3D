/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:49:29 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/05/27 21:06:42 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(int n)
{
	size_t	size;

	size = 1;
	if (n == -2147483648)
	{
		size += 2;
		n = (n % 1000000000) * -1;
	}
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*return_str;
	size_t	size;

	size = num_len(n);
	return_str = malloc(sizeof(char) * (size + 1));
	if (!return_str)
		return (NULL);
	return_str[size] = '\0';
	if (n < 0)
	{
		return_str[0] = '-';
		if (n == -2147483648)
			return_str[1] = '2';
		n = (n % 1000000000) * -1;
	}
	while (n > 9)
	{
		return_str[size - 1] = (n % 10) + 48;
		n /= 10;
		size--;
	}
	return_str[size - 1] = n + 48;
	return (return_str);
}
