/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:04:58 by llalba            #+#    #+#             */
/*   Updated: 2021/08/06 17:14:19 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (argc <= 1)
		return (0);
	s.stack_a = 0;
	s.stack_b = 0;
	s.parts = 0;
	s.len = ft_stacksize(argc, argv);
	if (s.len == -1 || s.len > MAX_STACK_LEN)
		ft_error();
	if (ft_load(&s.stack_a, argc, argv) == -1)
	{
		ft_lstclear(&s.stack_a, lstdel);
		ft_error();
	}
	if (s.len)
		solve(&s);
	ft_lstclear(&s.stack_a, lstdel);
	ft_lstclear(&s.stack_b, lstdel);
	ft_lstclear(&s.parts, lstdel);
	return (0);
}
