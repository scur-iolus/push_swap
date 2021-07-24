/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:18:03 by llalba            #+#    #+#             */
/*   Updated: 2021/07/24 18:14:03 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static short	in_lower_half(t_stacks *s, int top_len, int bottom_len)
{
// -20 -1 -22 -25 -11 1 -6 11 4 -19 20 21 -2 12 23 24 -16 3 -3 10 -14 8 -23 -15 16 18 0 2 -5 -13 6 -21 14 -7 -18 -10 5 -8 13 9 17 15 -9 -24 19 -4 -17 7 22 -12
	int			i;
	int			n;
	int			deepth;

	i = 0;
	n = (int)head->content;
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

static short	in_upper_half(t_list *head)
{
	int			i;
	int			n;
	int			deepth;

	i = 0;
	n = (int)head->content;
	while (head)
	{
		if (n > (int)head->content)
			i++;
		if ((10 * (long)i) >= 10 * (long)len / 2)
			return (1);
		head = head->next;
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
	int	bottom_len;

	free(ft_lstpop(&s->parts));
	// envoyer la ligne d'avant dans merge_sort maybe
	part_len = deepth;
	bottom_len = 0;
	printf("=============== a_to_b\n"); // ====
	print_stack(s->stack_a, "stack A"); // ====
	print_stack(s->stack_b, "stack B"); // ====
	print_stack(s->parts, "parts"); // ====
	while (part_len > deepth / 2 + deepth % 2)
	{
		//if (ft_lstsize(s->stack_b) == 3)
		//	sort3_b(s); //
		if (in_lower_half(s, part_len - bottom_len, bottom_len))
		{
			execute("pb", s);
			part_len--;
			move_b_top(s);
		}
		else
		{
			execute("ra", s);
			bottom_len++;
		}
	}
	printf("\n Avant rembobinage\n"); //= 
	print_stack(s->stack_a, "stack A"); // ====
	print_stack(s->stack_b, "stack B"); // ====
	print_stack(s->parts, "parts"); // ====
	while (bottom_len)
	{
		execute("rra", s);
		bottom_len--;
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
	while (curr_len > init_len / 2 + init_len % 2)
	{
		// if (curr_len == 3)
		//	sort3_b(s);
		// if (ft_lstsize(s->stack_a) == 3)
		//	sort3_a(s);
		if (in_upper_half(s->stack_b))
		{
			execute("pa", s);
			curr_len--;
		}
		else
			execute("rb", s);
	}
	return (init_len - curr_len);
}
