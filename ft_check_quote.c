/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:48:03 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/04 08:13:03 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_ex_i(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 34 || line[i] == 39)
			return (line[i]);
		i++;
	}
	return (-1);
}

char	*ft_remove_c2(char *line, int c)
{
	char	*new;
	int		i;
	int		j;

	if (ft_count_c(line, c) == 0)
		return (line);
	new = malloc((ft_strlen(line) - ft_count_c(line, c) + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != c)
			new[j++] = line[i];
		i++;
	}
	new[j] = '\0';
	free(line);
	return (new);
}

char	*ft_remove_db2(char *l, int x, int len, int i)
{
	char	*new;
	int		ch;
	int		c;

	new = malloc((len + 1) * sizeof(char));
	c = ft_ex_i(l);
	len = 0;
	ch = 0;
	while (l[i])
	{
		if (l[i] != c)
			new[len++] = l[i];
		if (c == l[i])
			ch++;
		i++;
		if (ch % 2 == 0 && ch != 0)
		{
			ch = 0;
			c = ft_ex_i(l + i);
		}
	}
	new[len] = '\0';
	if (x == 1)
		free(l);
	return (new);
}

char	*ft_remove_db(char *l, int x)
{
	int		ch;
	int		i;
	int		c;
	int		len;

	i = 0;
	c = ft_ex_i(l);
	len = 0;
	ch = 0;
	while (l[i])
	{
		if (l[i] != c)
			len++;
		if (c == l[i])
			ch++;
		i++;
		if (ch % 2 == 0 && ch != 0)
		{
			ch = 0;
			c = ft_ex_i(l + i);
		}
	}
	return (ft_remove_db2(l, x, len, 0));
}

int	ft_check_quote(char **full_cmd)
{
	int	i;

	i = 0;
	while (full_cmd[i])
	{
		if (ft_chrafterr(full_cmd[i], ft_strlen(full_cmd[i])) == 0)
		{
			ft_putstr_fd("Parse error: Unclosed Quotes\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
