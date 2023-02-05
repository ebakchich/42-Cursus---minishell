/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:06:34 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/04 23:26:29 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_red_chr(char *line)
{
	int		i;
	char	*c;

	c = "\n";
	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '<' || line[i] == '>' || line[i] == '|' || line[i] == '\0')
	{
		printf("gparse error near '%c'\n", line[i]);
		return (-1);
	}
	return (0);
}

int	ft_chrafter(char *line, int i, int c)
{
	int	k;

	k = 0;
	while (i >= 0)
	{
		if (line[i]  == c)
			k++;
		i--;
	}
	if (k % 2)
		return (0);
	return (1);
}

int	ft_check_error(char *line, char *l, int x)
{
	int		i;

	i = 0;
	if (l[0] == '|')
	{
		printf("parse error near '%c'\n", line[i]);
		return (-1);
	}
	while(line[i])
	{
		if (ft_chrafter(l, x, 34) && ft_chrafter(l, x, 39) && line[i] == '<' && line[i + 1] == '<')
			return (ft_red_chr(&line[i + 2]));
		else if (ft_chrafter(l, x, 34) && ft_chrafter(l, x, 39) && line[i] == '>' && line[i + 1] == '>')
			return (ft_red_chr(&line[i + 2]));
		else if (ft_chrafter(l, x, 34) && ft_chrafter(l, x, 39) && line[i] == '>')
			return (ft_red_chr(&line[i + 1]));
		else if (ft_chrafter(l, x, 34) && ft_chrafter(l, x, 39) && line[i] == '<')
			return (ft_red_chr(&line[i + 1]));
		else if (ft_chrafter(l, x, 34) && ft_chrafter(l, x, 39) && line[i] == '|')
			return (ft_red_chr(&line[i + 1]));
		i++;
	}
	return (0);
}

void	ft_parse(char *line)
{
	char	**full_cmd;
	int	i;

	//ft_check_quote(line);
	i = 0;
	while (line[i])
	{
		if (ft_strchr("<>|", line[i]))
		{
			if (ft_check_error(line + i, line, i))
				return ;
		}
		i++;
	}
	if (line[0] != '\0')
		full_cmd = ft_split(line, '|');
	// if (full_cmd == NULL)
	// {
	// 	printf("parse error\n");
	// 	return ;
	// }
	//ft_getcmd(line, full_cmd, cmd);
	i = 0;
	while (full_cmd[i])
	{
		printf("%s\n", full_cmd[i]);
		i++;
	}
	free(full_cmd);
}

int	main(void)
{
	char	*line;

	while (1)
	{
		line = readline("\033[32;1m\U000025B6\033[0m \033[32;1mminishell $>\033[0m ");
		ft_parse(line);
		free(line);
	}
	return (0);
}
