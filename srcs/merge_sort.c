/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:18:03 by llalba            #+#    #+#             */
/*   Updated: 2021/07/23 16:58:25 by llalba           ###   ########.fr       */
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
		if (n > (int)head->content)
			i++;
		if ((10 * (long)i) >= 10 * (long)len / 2)
			return (1);
		head = head->next;
		deepth++;
	}
	return (0);
}

static void	move_b_top(t_stacks *s)
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

int	a_to_b(t_stacks *s, int deepth)
{
	int	part_len;
	int	rev;

	free(ft_lstpop(&s->parts));
	part_len = deepth;
	// printf("=============== a_to_b\n"); // ====
	// print_stack(s->stack_a, "stack A"); // ====
	// print_stack(s->stack_b, "stack B"); // ====
	// print_stack(s->parts, "parts"); // ====
	while (!is_sorted(s) && part_len > deepth / 2 + deepth % 2)
	{
		if (part_len == 3)
			sort3_a(s); //
		if (ft_lstsize(s->stack_b) == 3)
			sort3_b(s); //
		if (in_lower_half(s->stack_a, (int)s->stack_a->content, deepth))
		{
			execute("pb", s);
			part_len--;
			move_b_top(s);
		}
		else
			execute("ra", s);
	}
	rev = part_len;
	while (rev)
	{
		execute("rra", s);
		rev--;
	}
	return (part_len);
}

int	b_to_a(t_stacks *s)
{
	int	init_len;
	int	curr_len;

	init_len = ft_lstsize(s->stack_b);
	curr_len = init_len;
	// printf("=============== b_to_a\n"); // ====
	// print_stack(s->stack_a, "stack A"); // ====
	// print_stack(s->stack_b, "stack B"); // ====
	// print_stack(s->parts, "parts"); // ====
	if (curr_len == 1)
		execute("pa", s);
	while (!is_sorted(s) && curr_len > init_len / 2 + init_len % 2)
	{
		// if (curr_len == 3)
		//	sort3_b(s);
		if (ft_lstsize(s->stack_a) == 3)
			sort3_a(s);
		if (in_upper_half(s->stack_b, (int)s->stack_b->content, init_len))
		{
			execute("pa", s);
			curr_len--;
		}
		else
			execute("rb", s);
	}
	return (init_len - curr_len);
}
