/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:43:47 by llalba            #+#    #+#             */
/*   Updated: 2021/06/27 16:03:36 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	size_t				i;
	long long			is_positive;
	unsigned long long	nbr;

	i = 0;
	nbr = 0;
	is_positive = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_positive = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nbr = 10 * nbr + (str[i] - 48);
		str++;
	}
	return (is_positive * (long long)nbr);
}
