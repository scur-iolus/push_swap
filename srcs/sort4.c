/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:20:24 by llalba            #+#    #+#             */
/*   Updated: 2021/07/29 15:39:02 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

short	sort4_a(int a_len, t_stacks *s)
{
	int	i;

	i = 4;
	if (a_len != i)
		return (0);
	execute("pb", s);
	sort3_a(s->stack_a, 3, s);
	while (i)
	{
		if (s->stack_b && ((v(s->stack_a) > v(s->stack_b)) || i == 1))
			execute("pa", s);
		execute("ra", s);
		i--;
	}
	return (1);
}
