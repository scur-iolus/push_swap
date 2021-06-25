/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:04:48 by llalba            #+#    #+#             */
/*   Updated: 2021/06/25 15:41:02 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>
# include "../libft/libft.hc"

typedef struct	s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		len;
}				t_stacks


/*
** utils.c
*/

void	lstdel(void *element);
void	ft_error();
void	free_r(char **ptr);
short	is_int(char *str);

#endif
