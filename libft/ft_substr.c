/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:38:11 by llalba            #+#    #+#             */
/*   Updated: 2021/05/21 15:24:38 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	substr_len;
	char	*sub;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return ((char *)ft_calloc(1, 1));
	if (len_s - start >= len)
		substr_len = len;
	else
		substr_len = len_s - start;
	sub = (char *)malloc(substr_len + 1);
	if (sub)
	{
		ft_memcpy(sub, s + start, substr_len);
		sub[substr_len] = 0;
	}
	return (sub);
}
