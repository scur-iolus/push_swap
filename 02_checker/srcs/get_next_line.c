/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:21:33 by llalba            #+#    #+#             */
/*   Updated: 2021/07/30 13:46:03 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*ft_calloc(int len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static short	update_output(char **output, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *output;
	*output = ft_calloc(ft_strlen(*output) + 2);
	if (!(*output))
		return (0);
	while (tmp[i])
	{
		(*output)[i] = tmp[i];
		i++;
	}
	(*output)[i] = c;
	free(tmp);
	return (1);
}

int	get_next_line(char **line)
{
	int		ret;
	char	c;
	char	*output;

	output = ft_calloc(1);
	ret = read(0, &c, 1);
	while (ret > 0 && c != '\n')
	{
		if (!update_output(&output, c))
			return (-1);
		ret = read(0, &c, 1);
	}
	if (ret == -1)
		return (-1);
	*line = output;
	if (ret == 1)
		return (1);
	return (0);
}
