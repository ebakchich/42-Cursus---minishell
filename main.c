/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:06:34 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/28 15:33:02 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_pipe(char *line)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == '|')
			k++;
		i++;
	}
	return (k);
}

void	ft_getcmd(char *line, char **full_cmd, t_cmd cmd)
{
	int	i;

	i = 0;
	
}

void	ft_parse(char *line)
{
	char	**full_cmd;
	t_cmd	*cmd;

	cmd = malloc((ft_count_pipe(line) + 2) * sizeof(t_cmd));
	full_cmd = ft_split(line, '|');
	ft_getcmd(line, full_cmd, cmd);
	free(cmd);
}

int	main(void)
{
	char	*line;

	while (1)
	{
		line = readline("\U0001F7E2 \033[32;1mminishell $>\033[0m ");
		ft_parse(line);
		free(line);
	}
	return (0);
}
