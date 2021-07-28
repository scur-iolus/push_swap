/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:04:58 by llalba            #+#    #+#             */
/*   Updated: 2021/07/28 17:31:47 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static long	ft_stacksize(int argc, char **argv)
{
	long	size;
	int		i;
	int		j;
	char	**split;

	size = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		while (split[j])
		{
			if (!is_int(split[j]))
				return (free_str_ptr(&split));
			size++;
			j++;
		}
		(void)free_str_ptr(&split);
		i++;
	}
	return (size);
}

static short	is_new(t_list *tmp, int nbr)
{
	while (tmp)
	{
		if ((int)(tmp->content) == nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	ft_load(t_list **stack, int argc, char **argv)
{
	int			i;
	int			j;
	long long	nbr;
	char		**split;

	i = 1;
	while (i < argc)
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		while (split[j])
		{
			nbr = ft_atoi(split[j]);
			if (ft_strlen(split[j]) > 18 || nbr < -2147483648 || \
					nbr > 2147483647 || !is_new(*stack, (int)nbr))
				return (free_str_ptr(&split));
			ft_lstadd_back(stack, ft_lstnew((void *)nbr));
			j++;
		}
		(void)free_str_ptr(&split);
		i++;
	}
	return (1);
}

void	print_stack(t_list *tmp, const char *str) // =============================================================
{
	if (tmp)
		printf("[%s] %d elem >>>", str, ft_lstsize(tmp));
	else
		printf("[%s] >>> vide.", str);
	while (tmp)
	{
		printf(" %d", (int)(tmp->content));
		tmp = tmp->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_stacks	s;

	if (argc <= 1)
		ft_error();
	stack_a = 0;
	stack_b = 0;
	s.len = ft_stacksize(argc, argv);
	if (s.len == -1 || s.len > 10000)
		ft_error();
	s.stack_a = stack_a;
	s.stack_b = stack_b;
	if (ft_load(&s.stack_a, argc, argv) == -1)
	{
		ft_lstclear(&s.stack_a, lstdel);
		ft_error();
	}
	solve(&s);
	//print_stack(s.stack_a, "A"); // =
	//print_stack(s.stack_b, "B"); //= 
	ft_lstclear(&s.stack_a, lstdel);
	ft_lstclear(&s.stack_b, lstdel);
	ft_lstclear(&s.parts, lstdel);
	return (0);
}
