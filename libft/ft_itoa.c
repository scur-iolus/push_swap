/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:09:53 by llalba            #+#    #+#             */
/*   Updated: 2021/05/25 16:54:57 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_malloc_size(long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n - (n % 10) != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	signed long	i;
	size_t		len;
	char		*output;
	long		nb;

	nb = n;
	len = get_malloc_size(nb);
	i = len - 1;
	output = (char *)ft_calloc(1, sizeof(char) * (len + 1));
	if (!output)
		return (0);
	if (nb < 0)
	{
		output[0] = '-';
		nb = -nb;
	}
	while ((i >= 0 && output[0] != '-') || (i > 0 && output[0] == '-'))
	{
		output[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (output);
}
