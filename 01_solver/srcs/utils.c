/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:42:44 by llalba            #+#    #+#             */
/*   Updated: 2021/08/06 17:49:18 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	lstdel(void *element)
{
	return ((void)element);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	free_str_ptr(char ***ptr)
{
	int	i;

	i = 0;
	while ((*ptr)[i])
	{
		free((*ptr)[i]);
		(*ptr)[i] = 0;
		i++;
	}
	free(*ptr);
	ptr = 0;
	return (-1);
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

void	execute(const char *str, t_stacks *s)
{
	if (str[0] == 's')
	{
		if (str[1] == 'a' || str[1] == 's')
			swap(&s->stack_a);
		if (str[1] == 'b' || str[1] == 's')
			swap(&s->stack_b);
	}
	else if (str[0] == 'p' && str[1] == 'a')
		push(&s->stack_b, &s->stack_a);
	else if (str[0] == 'p' && str[1] == 'b')
		push(&s->stack_a, &s->stack_b);
	else if (str[0] == 'r')
	{
		if (str[1] == 'a' || (str[1] == 'r' && !str[2]))
			rotate(&s->stack_a);
		if (str[1] == 'b' || (str[1] == 'r' && !str[2]))
			rotate(&s->stack_b);
		if ((str[1] == 'r' && str[2] == 'a') || str[2] == 'r')
			rev_rotate(&s->stack_a);
		if ((str[1] == 'r' && str[2] == 'b') || str[2] == 'r')
			rev_rotate(&s->stack_b);
	}
	write(1, str, ft_strlen(str));
	ft_putchar_fd('\n', 1);
}
