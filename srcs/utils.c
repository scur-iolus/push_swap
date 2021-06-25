/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:42:44 by llalba            #+#    #+#             */
/*   Updated: 2021/06/25 16:07:09 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	lstdel(void *element)
{
	element = 0;
}

void	ft_error()
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	free_r(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = 0;
		i++;
	}
	free(ptr);
	ptr = 0;
}

short	is_int(char *str)
{
	short	has_digits;

	has_digits = 0;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		has_digits = 1;
	}
	return (*str == 0 && has_digits);
}
