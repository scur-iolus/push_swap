/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:01:55 by llalba            #+#    #+#             */
/*   Updated: 2021/05/25 18:06:05 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	length;
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	length = 0;
	while (src[length])
		length++;
	while (i < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize && i == dstsize)
		dst[dstsize - 1] = '\0';
	if (dstsize && i < dstsize)
		dst[i] = '\0';
	return (length);
}
