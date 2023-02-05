/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:48:03 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/02 20:34:23 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_c(char *line, int c)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == c)
			k++;
		i++;
	}
	return (k);
}

void	ft_remove_96(char *line)
{
	int i;
	int	k;

	i = 0;
	while (line[i])
	{
		if (line[i] == 96)
		{
			k = i;
			while (line[k + 1])
			{
				line[k] = line[k + 1];	
				k++;
			}
			line[k] = '\0';
			i = 0;
		}
		i++;
	}
	if (line[0] == '`')
		line[0] = '\0';
}

int	ft_check_quote(char *line)
{
	if (ft_count_c(line, 96) % 2)
	{
		printf("Parse error: Unclosed Quotes\n");
		return (1);
	}
	if (ft_strchr(line, '`'))
		ft_remove_96(line);
	// ft_check_dbq(line);
	return (0);
}
