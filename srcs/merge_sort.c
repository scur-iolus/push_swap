/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:18:03 by llalba            #+#    #+#             */
/*   Updated: 2021/07/22 20:31:26 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static short	in_lower_half(t_list *head, int n, int len)
{
	int			i;
	int			deepth;

	i = 0;
	deepth = 0;
	while (head && deepth < len)
	{
		if (n < (int)head->content)
			i++;
		if ((10 * (long)i) >= 10 * (long)len / 2)
			return (1);
		head = head->next;
		deepth++;
	}
	return (0);
}

static short	in_upper_half(t_list *head, int n, int len)
{
	int			i;
	int			deepth;

	i = 0;
	deepth = 0;
	while (head && deepth < len)
	{
		if (n > (int)head->content || len == 1)
			i++;
		if ((10 * (long)i) >= 10 * (long)len / 2)
			return (1);
		head = head->next;
		deepth++;
	}
	return (0);
}

void	move_b_top(t_stacks *s)
{
	int	b_len;

	b_len = ft_lstsize(s->stack_b);
	if (b_len >= 3)
		if ((int)s->stack_b->content < (int)ft_lstlast(s->stack_b)->content)
			execute("rb", s);
	if (b_len >= 2)
		if ((int)s->stack_b->content < (int)s->stack_b->next->content)
			execute("sb", s);
}

/*
void	move_a_top(t_stacks *s)
{
	int	a_len;

	a_len = ft_lstsize(s->stack_a);
	if (a_len >= 3)
		if ((int)s->stack_a->content > (int)ft_lstlast(s->stack_a)->content)
			execute("ra", s);
	if (a_len >= 2)
		if ((int)s->stack_a->content > (int)s->stack_a->next->content)
			execute("sa", s);
}
*/
