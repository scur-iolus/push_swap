/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:37:02 by llalba            #+#    #+#             */
/*   Updated: 2021/07/30 17:04:54 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static short	parse_operation(t_stacks *s, const char **op)
{
	if (!ft_strcmp("sa", *op))
		execute("sa", s);
	else if (!ft_strcmp("sb", *op))
		execute("sb", s);
	else if (!ft_strcmp("ss", *op))
		execute("ss", s);
	else if (!ft_strcmp("pa", *op))
		execute("pa", s);
	else if (!ft_strcmp("pb", *op))
		execute("pb", s);
	else if (!ft_strcmp("ra", *op))
		execute("ra", s);
	else if (!ft_strcmp("rb", *op))
		execute("rb", s);
	else if (!ft_strcmp("rr", *op))
		execute("rr", s);
	else if (!ft_strcmp("rra", *op))
		execute("rra", s);
	else if (!ft_strcmp("rrb", *op))
		execute("rrb", s);
	else if (!ft_strcmp("rrr", *op))
		execute("rrr", s);
	else
		return (0);
	return (1);
}

static int	stdin_parsing(t_stacks *s)
{
	char		*op;
	const char	*op_const;
	int			ret;

	op = 0;
	ret = get_next_line(&op);
	while (ret > 0)
	{
		op_const = op;
		if (!parse_operation(s, &op_const))
		{
			free(op);
			op = 0;
			return (0);
		}
		free(op);
		op = 0;
		ret = get_next_line(&op);
	}
	free(op);
	op = 0;
	return (1);
}

static void	verdict(t_stacks *s, short parsing_OK)
{
	short	is_KO;
	t_list	*tmp;

	is_KO = 0;
	if (!parsing_OK || s->stack_b)
		is_KO = 1;
	if (!is_KO && s->len)
	{
		tmp = s->stack_a;
		while (tmp->next && !is_KO)
		{
			if ((int)tmp->content >= (int)tmp->next->content)
				is_KO = 1;
			tmp = tmp->next;
		}
	}
	if (is_KO)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_lstclear(&s->stack_a, lstdel);
	ft_lstclear(&s->stack_b, lstdel);
	ft_lstclear(&s->parts, lstdel);
}

int	main(int argc, char **argv)
{
	t_stacks	s;
	short		parsing_OK;

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
	parsing_OK = stdin_parsing(&s);
	verdict(&s, parsing_OK);
	return (0);
}
