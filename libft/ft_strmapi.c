/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:21:15 by llalba            #+#    #+#             */
/*   Updated: 2021/05/25 09:54:56 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*s_cpy;
	size_t	i;

	i = 0;
	if (f == 0 || s == 0)
		return (0);
	len = ft_strlen(s);
	s_cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!s_cpy)
		return (0);
	ft_strlcpy(s_cpy, s, len + 1);
	while (s_cpy[i])
	{
		s_cpy[i] = (*f)((unsigned int)i, s_cpy[i]);
		i++;
	}
	return (s_cpy);
}
