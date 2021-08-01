/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:21:00 by llalba            #+#    #+#             */
/*   Updated: 2021/08/01 14:17:39 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

long	ft_stacksize(int argc, char **argv)
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
		while (split && split[j])
		{
			if (!is_int(split[j]))
				return (free_str_ptr(&split));
			size++;
			j++;
		}
		if (split)
			(void)free_str_ptr(&split);
		i++;
	}
	return (size);
}

static short	is_new(t_list *tmp, int nbr)
{
	while (tmp)
	{
		if (v(tmp) == nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

short	ft_load(t_list **stack, int argc, char **argv)
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
		while (split && split[j])
		{
			nbr = ft_atoi(split[j]);
			if (ft_strlen(split[j]) > 18 || nbr < -2147483648 || \
					nbr > 2147483647 || !is_new(*stack, (int)nbr))
				return (free_str_ptr(&split));
			ft_lstadd_back(stack, ft_lstnew((void *)nbr));
			j++;
		}
		if (split)
			(void)free_str_ptr(&split);
		i++;
	}
	return (1);
}
