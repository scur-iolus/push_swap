/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:18:16 by llalba            #+#    #+#             */
/*   Updated: 2021/05/25 16:09:49 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*(char *)(s1 + i) != *(char *)(s2 + i))
			return ((unsigned char)*(char *)(s1 + i) - \
					(unsigned char)*(char *)(s2 + i));
		else
			i++;
	}
	return (0);
}
