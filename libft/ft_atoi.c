/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:43:47 by llalba            #+#    #+#             */
/*   Updated: 2021/05/25 15:18:59 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t				i;
	int					is_positive;
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
	return (is_positive * nbr);
}
