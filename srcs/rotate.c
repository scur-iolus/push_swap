/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:49:28 by llalba            #+#    #+#             */
/*   Updated: 2021/06/28 09:40:55 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (*stack == 0 || (*stack)->next == 0)
		return ;
	tmp = *stack;
	ft_lstlast(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = 0;
}

void	double_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	rev_rotate(t_list **stack)
{
	t_list	*tmp;

	if (*stack == 0 || (*stack)->next == 0)
		return ;
	tmp = *stack;
	*stack = ft_lstlast(*stack);
	ft_lstsecondtolast(tmp)->next = 0;
	(*stack)->next = tmp;
}

void	dble_rev_rotate(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
