/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:01:49 by llalba            #+#    #+#             */
/*   Updated: 2021/05/27 10:55:16 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	while (dst[j] && j <= dstsize)
		j++;
	if (j > dstsize)
		return (dstsize + ft_strlen(src));
	i = 0;
	k = j;
	if (dstsize > 0)
	{
		while (src[i] && j < dstsize - 1)
			dst[j++] = src[i++];
		dst[j] = 0;
	}
	if (k > dstsize)
		k = dstsize;
	return (k + ft_strlen(src));
}
