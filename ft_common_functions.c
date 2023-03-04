/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:13:54 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/04 03:40:05 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_c(char *line, int c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_count_str(char **token, char *str)
{
	int		i;
	size_t	len;
	int		count;

	i = 0;
	count = 0;
	while (token[i])
	{
		len = ft_strlen(str);
		if (len < ft_strlen(token[i]))
			len = ft_strlen(token[i]);
		if (ft_memcmp(token[i], str, len) == 0)
			count++;
		len = ft_strlen(str);
		i++;
	}
	return (count);
}

int	ft_chrq(char *line, int j, int i)
{
	while (i < j)
	{
		if (line[i] == 34 || line[i] == 39)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_chrafterr(char *line, int j)
{
	int		i;
	char	c;
	int		count;

	count = 0;
	i = ft_chrq(line, j, 0);
	if ((line[i] != 34 && line[i] != 39) || i == -1)
		return (1);
	c = line[i];
	while (i < j)
	{
		if (line[i] == c)
			count++;
		i++;
		if ((count % 2) == 0 && count != 0)
		{
			i = ft_chrq(line, j, i);
			c = line[i];
			if ((line[i] != 34 && line[i] != 39) || i == -1)
				return (1);
		}
	}
	if (count % 2)
		return (0);
	return (1);
}

void	ft_chng_c(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_chrafterr(line, i) && line[i] == c)
			line[i] = -1;
		i++;
	}
}
