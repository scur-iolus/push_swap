/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:02:20 by llalba            #+#    #+#             */
/*   Updated: 2021/05/26 14:38:46 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	found;
	size_t	i;
	size_t	needle_len;
	char	*tmp;

	tmp = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (!needle_len)
		return (tmp);
	i = 0;
	while (tmp[i] && i < len)
	{
		found = 0;
		while (tmp[i + found] && needle[found] && \
				tmp[i + found] == needle[found] && (i + found) < len)
		{
			found++;
		}
		if (found == needle_len)
			return (tmp + i);
		i++;
	}
	return (0);
}
