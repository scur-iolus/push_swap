/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:04:58 by llalba            #+#    #+#             */
/*   Updated: 2021/06/25 16:07:24 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stacksize(int argc, char **argv)
{
	int		size;
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
			{
				free_r(split);
				return (-1);
			}
			free(split[j]);
			size++;
			j++;
		}
		free(split);
		i++;
	}
	return (size);
}

int	ft_load(t_list *stack, int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		while (split[j])
		{
			split[j] // ici, cf check_args dans checks.c
			j++;
			free(split[j]);
		}
		free(split);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list		stack_a;
	t_list		stack_b;
	t_stacks	s;

	if (argc > 1)
	{
		stack_a = 0;
		stack_b = 0;
		s.len = ft_stacksize(argc, argv);
		if (s.len == -1)
			ft_error();
		s.stack_a = &stack_a;
		s.stack_b = &stack_b;
		if (ft_load(&stack_a, argc, argv) == -1)
			ft_error();
		// ft_verif dans push_swap.c
// si certains parametres ne sont pas des nombres, erreur
// si certains parametres ne tiennt pas dans un int
// s'il y a des doublons
	}
	else
		ft_error();
	return (0);
}
