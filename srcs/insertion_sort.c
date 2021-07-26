/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:08:59 by llalba            #+#    #+#             */
/*   Updated: 2021/07/26 13:00:21 by llalba           ###   ########.fr       */
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
