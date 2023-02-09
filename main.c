/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:06:34 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/09 03:53:09 by ebakchic         ###   ########.fr       */
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
	int 	count;

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

void	ft_chng_pipe(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_chrafterr(line, i) && line[i] == '|')
			line[i] = -1;
		i++;
	}
}

int	ft_check_error(char *line, char *l, int x)
{
	int		i;

	i = 0;
	if (l[0] == '|' || l[ft_strlen(l) - 1] == '|')
	{
		printf("parse error near '%c'\n", line[i]);
		return (-1);
	}
	while(line[i])
	{
		if (ft_chrafterr(l, x) && line[i] == '<' && line[i + 1] == '<')
			return (ft_red_chr(&line[i + 2]));
		else if (ft_chrafterr(l, x) && line[i] == '>' && line[i + 1] == '>')
			return (ft_red_chr(&line[i + 2]));
		else if (ft_chrafterr(l, x) && line[i] == '>')
			return (ft_red_chr(&line[i + 1]));
		else if (ft_chrafterr(l, x) && line[i] == '<')
			return (ft_red_chr(&line[i + 1]));
		if (ft_chrafterr(l, x) && line[i] == '|')
			return (ft_red_chr(&line[i + 1]));
		i++;
	}
	return (0);
}

void	ft_parse(char *line, char **env)
{
	t_cmd	*cmd;
	char	**full_cmd;
	int	i;

	if (line[0] == '\0')
		return ;
	i = 0;
	while (line[i])
	{
		if (ft_strchr("<>|", line[i]))
			if (ft_check_error(line + i, line, i))
				return ;
		i++;
	}
	ft_chng_pipe(line);
	full_cmd = ft_split(line, -1);
	if (full_cmd == NULL)
		return ;
	if (ft_check_quote(full_cmd))
		return ;
	cmd = ft_getcmd(full_cmd, env);
	i = 0;
	while (full_cmd[i])
	{
		printf("%s\n", full_cmd[i]);
		i++;
	}
	free(full_cmd);
}

int	main(int ac, char **av, char **env)
{
	char	*line;

	while (1)
	{
		line = readline("\033[32;1m\U000025B6\033[0m \033[32;1mminishell $>\033[0m ");
		ft_parse(line, env);
		free(line);
	}
	return (0);
}
