/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:08:59 by llalba            #+#    #+#             */
/*   Updated: 2021/07/26 16:27:03 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	insertion_sort_A(t_stacks *s, int deepth)
{
	int		i;

	if (deepth == 3 && ft_lstsize(s->stack_a) == 3)
	{
		sort3_a(s);
		return ;
	}
	i = 1;
	while (i <= deepth)
	{
		if (i < deepth)
			if ((int)s->stack_a->content > (int)s->stack_a->next->content)
				execute("sa", s);
		if (i == 1 || (int)ft_lstlast(s->stack_a)->content < \
				(int)s->stack_a->content)
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
}

static void	update_min(t_list **min, t_list *tmp, int *pos, int i)
{
	if (!(*min) || (int)(*min)->content > (int)tmp->content)
	{
		*min = tmp;
		*pos = i;
	}
}

static int	get_min_pos(t_stacks *s, int a_deepth)
{
	int		i;
	int		pos;
	t_list	*tmp;
	t_list	*min;

	i = 0;
	if (a_deepth)
		tmp = s->stack_a;
	min = 0;
	while (i < a_deepth)
	{
		update_min(&min, tmp, &pos, i);
		i++;
		tmp = tmp->next;
	}

	tmp = s->stack_b;
	i = -1;
	while (tmp)
	{
		update_min(&min, tmp, &pos, i);
		i--;
		tmp = tmp->next;
	}
	return (pos);
}

static void	shift_min_B(t_stacks *s, int *b_deepth, int *a_deepth, int *min_pos)
{
	int	worst_case;

	worst_case = (*b_deepth) / 2;
	//printf("worst_case : %d, min_pos :%d\n", worst_case, *min_pos); //=
	//print_stack(s->stack_a, "stack a"); //==
	//print_stack(s->stack_b, "stack b"); //==
	if (*min_pos == -1 || worst_case + 1 > *a_deepth - 1)
	{
		(*b_deepth)--;
		(*a_deepth)++;
		execute("pa", s);
		(*min_pos)++;
	}
	else if (worst_case > -(*min_pos) / 2)
	{
		execute("rb", s);
		(*min_pos)++;
	}
	else
	{
		execute("rrb", s);
		(*min_pos)--;
		if (*min_pos < -(*b_deepth))
			*min_pos = -1;
	}
}

void	insertion_sort_AB(t_stacks *s, int deepth)
{
	int		a_deepth;
	int		b_deepth;
	int		min_pos;

	a_deepth = deepth;
	b_deepth = 0;
	while (a_deepth + b_deepth)
	{
		min_pos = get_min_pos(s, a_deepth);
		//printf("a_deepth %d, b_deepth %d, min_pos %d\n", a_deepth, b_deepth, min_pos); //=
		//print_stack(s->stack_a, "stack a"); //==
		//print_stack(s->stack_b, "stack b"); //==
		while (min_pos)
		{
			if (min_pos < 0)
				shift_min_B(s, &b_deepth, &a_deepth, &min_pos);
			else
			{
				a_deepth--;
				b_deepth++;
				execute("pb", s);
				min_pos--;
			}
		}
		a_deepth--;
		if (s->stack_a->next)
			execute("ra", s);
	}
}
