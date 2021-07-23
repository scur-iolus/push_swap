/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:43:01 by llalba            #+#    #+#             */
/*   Updated: 2021/07/23 17:02:51 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void	insertion_sort(t_stacks *s, int deepth)
{
	t_list	*bottom;
	int		i;

	printf("=============== insertion_sort ==============\n"); // ====
	i = 1;
	if (is_sorted(s))
		return ;
	while (i <= deepth)
	{
		//print_stack(s->stack_a, "stack A"); // ====
		//print_stack(s->stack_b, "stack B"); // ====
		bottom = ft_lstlast(s->stack_a);
		if (i < deepth && \
				(int)s->stack_a->content > (int)s->stack_a->next->content)
			execute("sa", s);
		if (i == 1 || (int)bottom->content < (int)s->stack_a->content)
		{
			execute("ra", s);
			i++;
		}
		else
		{
			execute("rra", s);
			i--;
		}
	}
/*i
	t_list	*tmp;
	t_list	*min;
	int		i;

	if (!ft_lstsize(s->stack_a))
		return ;
	i = 0;
	tmp = s->stack_a;
	min = tmp;
	while (i < deepth)
	{
		if ((int)min->content > (int)tmp->content)
			min = tmp;
		i++;
		tmp = tmp->next;
	}
	tmp = s->stack_a;
	i = 0;
	while (deepth)
	{
		while ((int)min->content != (int)tmp->content)
		{
			tmp = tmp->next;
			execute("pb", s);
			move_b_top(s);
		}
		execute("ra", s);
		deepth--;
	}
*/
}

static void	merge_sort(t_stacks *s)
{
	int		part_len;

	printf("==================== merge sort ================\n"); //=====
	print_stack(s->stack_a, "stack A avant"); // ====
	print_stack(s->stack_b, "stack B avant"); // ====
	part_len = a_to_b(s, (int)s->parts->content);
	print_stack(s->stack_a, "stack A ATOB"); // ====
	print_stack(s->stack_b, "stack B ATOB"); // ====
	ft_lstadd_front(&s->parts, ft_lstnew((void *)(size_t)part_len));
	part_len = 2;
	while (!is_sorted(s) && part_len > 1)
	{
		part_len = b_to_a(s);
		ft_lstadd_front(&s->parts, ft_lstnew((void *)(size_t)part_len));
	}
	ft_lstadd_front(&s->parts, ft_lstnew((void *)(size_t)part_len));
	print_stack(s->stack_a, "stack A apres"); // ====
	print_stack(s->stack_b, "stack B apres"); // ====
}

void	solve(t_stacks *s)
{
	int		a_len;

	a_len = ft_lstsize(s->stack_a);
	ft_lstadd_front(&s->parts, ft_lstnew((void *)(size_t)a_len));
	while (!is_sorted(s))
	{
		if ((int)s->parts->content < THRESHOLD)
		{
			print_stack(s->parts, "parts avant"); // ====
			insertion_sort(s, (int)s->parts->content);
			free(ft_lstpop(&s->parts));
		}
		else
			merge_sort(s);
	}
}
