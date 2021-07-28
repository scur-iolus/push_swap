/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:12:44 by llalba            #+#    #+#             */
/*   Updated: 2021/07/28 16:17:12 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

short	sort3(t_stacks *s, t_list *a)
{
	short	case_3_1_2;
	short	case_1_3_2;
	short	case_3_2_1;
	short	case_2_3_1;
	short	case_2_1_3;

	if (!a || !a->next || !a->next->next || a->next->next->next)
		return (0);
	case_3_1_2 = (v(a) > v(a->next->next) && v(a->next->next) > v(a->next));
	case_1_3_2 = (v(a->next) > v(a->next->next) && v(a->next->next) > v(a));
	case_3_2_1 = (v(a) > v(a->next) && v(a->next) > v(a->next->next));
	case_2_3_1 = (v(a->next) > v(a) && v(a) > v(a->next->next));
	case_2_1_3 = (v(a->next->next) > v(a) && v(a) > v(a->next));
	if (case_2_1_3 || case_1_3_2 || case_3_2_1)
		execute("sa", s);
	if (case_1_3_2 || case_3_1_2)
		execute("ra", s);
	if (case_3_2_1 || case_2_3_1)
		execute("rra", s);
	return (1);
}

short	sort3_a(t_list *a, int a_len, t_stacks *s)
{
	short	case_3_1_2;
	short	case_1_3_2;
	short	case_3_2_1;
	short	case_2_3_1;
	short	case_2_1_3;

	if (a_len != 3)
		return (0);
	case_3_1_2 = (v(a) > v(a->next->next) && v(a->next->next) > v(a->next));
	case_1_3_2 = (v(a->next) > v(a->next->next) && v(a->next->next) > v(a));
	case_3_2_1 = (v(a) > v(a->next) && v(a->next) > v(a->next->next));
	case_2_3_1 = (v(a->next) > v(a) && v(a) > v(a->next->next));
	case_2_1_3 = (v(a->next->next) > v(a) && v(a) > v(a->next));
	if (case_3_1_2 || case_3_2_1)
		execute("sa", s);
	if (case_3_2_1 || case_3_1_2 || case_1_3_2 || case_2_3_1)
	{
		execute("pb", s);
		execute("sa", s);
		execute("pa", s);
	}
	if (case_3_2_1 || case_2_3_1 || case_2_1_3)
		execute("sa", s);
	return (1);
}

short	sort3_b(t_list *b, int b_len, t_stacks *s)
{
	short	case_1_3_2;
	short	case_3_1_2;
	short	case_1_2_3;
	short	case_2_1_3;
	short	case_2_3_1;

	if (b_len != 3)
		return (0);
	case_1_3_2 = (v(b->next) > v(b->next->next) && v(b->next->next) > v(b));
	case_3_1_2 = (v(b) > v(b->next->next) && v(b->next->next) > v(b->next));
	case_1_2_3 = (v(b->next->next) > v(b->next) && v(b->next) > v(b));
	case_2_1_3 = (v(b->next->next) > v(b) && v(b) > v(b->next));
	case_2_3_1 = (v(b->next) > v(b) && v(b) > v(b->next->next));
	case_3_1_2 = (v(b) > v(b->next->next) && v(b->next->next) > v(b->next));
	if (case_1_3_2 || case_1_2_3)
		execute("sb", s);
	if (case_1_2_3 || case_2_1_3 || case_1_3_2 || case_3_1_2)
	{
		execute("pa", s);
		execute("sb", s);
		execute("pb", s);
	}
	if (case_1_2_3 || case_2_1_3 || case_2_3_1)
		execute("sb", s);
	return (3 - case_3_1_2);
}
