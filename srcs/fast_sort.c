/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:12:44 by llalba            #+#    #+#             */
/*   Updated: 2021/07/26 12:19:22 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static int	v(t_list *l)
{
	return ((int)(l->content));
}

short	sort3_a(t_stacks *s)
{
	t_list	*a;

	a = s->stack_a;
	if (v(a) < v(a->next->next) && v(a->next->next) < v(a->next))
		execute("sa", s);
	a = s->stack_a;
	if (v(a->next->next) < v(a->next) && v(a->next) < v(a))
		execute("sa", s);
	a = s->stack_a;
	if (v(a->next) < v(a->next->next) && v(a->next->next) < v(a))
		execute("ra", s);
	a = s->stack_a;
	if (v(a->next->next) < v(a) && v(a) < v(a->next))
		execute("rra", s);
	a = s->stack_a;
	if (v(a->next) < v(a) && v(a) < v(a->next->next))
		execute("sa", s);
	return (1);
}
