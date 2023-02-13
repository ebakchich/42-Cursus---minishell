/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:48:03 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/13 04:25:15 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
