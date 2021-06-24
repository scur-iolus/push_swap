/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:16:58 by llalba            #+#    #+#             */
/*   Updated: 2021/05/25 15:33:18 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	src_len;

	src_len = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(char) * (src_len + 1));
	if (cpy == 0)
		return (cpy);
	while (src_len + 1)
	{
		cpy[src_len] = s1[src_len];
		src_len--;
	}
	return (cpy);
}
