/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:48:03 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/17 15:02:53 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    ft_ex_i(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == 34 || line[i] == 39)
            return (line[i]);
        i++;
    }
    return (-1);
}

int    ft_ex_i2(char *line, int c)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

void	ft_remove_c(char *line, int c)
{
	int	i;
	int	j;

	if (ft_count_c(line, c) == 0)
		return ;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
		{
			j = i;
			while (line[j])
			{
				line[j] = line[j + 1];
				j++;
			}
		}
		i++;
	}
}

char	*ft_remove_db(char *l)
{
	int	k;
	int	i;
	int	c;

	i = 0;
	k = 0;
	while (l[i])
	{
		c = ft_ex_i(l + i);
		if (l[i] == c)
		{
			ft_remove_c(l + i, c);
			c = ft_ex_i2(l, c);
			i = c;
			ft_remove_c(l + i, l[c]);
		}
		else
			i++;
	}
	return (l);
}

int	ft_check_quote(char **full_cmd)
{
	int	i;
	int	j;

	i = 0;
	while (full_cmd[i])
	{
		if (ft_chrafterr(full_cmd[i], ft_strlen(full_cmd[i])) == 0)
		{
			printf("Parse error: Unclosed Quotes\n");
			return (1);
		}
		i++;
	}
	return (0);
}
