/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:42:44 by llalba            #+#    #+#             */
/*   Updated: 2021/06/28 08:41:10 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	lstdel(void *element)
{
	element = 0;
}

void	ft_error()
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	free_str_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = 0;
		i++;
	}
	free(ptr);
	ptr = 0;
}

short	is_int(char *str)
{
	short	has_digits;

	has_digits = 0;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		has_digits = 1;
	}
	return (*str == 0 && has_digits);
}
