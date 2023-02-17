/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:53:29 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/17 22:09:40 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_dblen(char **full_cmd)
{
	int i;

	i = 0;
	while (full_cmd[i])
		i++;
	return (i);
}

void    ft_init_cmd(t_cmd *cmd, int x, char **env)
{
	int i;

	i = 0;
	while (i < x)
	{
		cmd[i].cmd = NULL;
		cmd[i].infile = NULL;
		cmd[i].outfile = NULL;
		cmd[i].her = NULL;
		cmd[i].apend = NULL;
		i++;
	}
}

int	ft_count_red(char *line)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '>' && line[i + 1] == '>')
		{
			i++;
			count++;
		}
		else if (line[i] == '<' && line[i + 1] == '<')
		{
			i++;
			count++;
		}
		else if (line[i] == '>')
			count++;
		else if (line[i] == '<')
			count++;
		i++;
	}
	return (count);
}

char    *ft_add_space(char *line)
{
	int		count;
	char	*new;
	int	i;
	int	j;

	count = ft_count_red(line);
	if (count == 0)
		return (line);
	new = malloc((ft_strlen(line) + (count * 2) + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '>' && line[i + 1] == '>')
		{
			new[j++] = ' ';
			new[j++] = line[i++];
			new[j++] = line[i++];
			new[j++] = ' ';
		}
		else if (line[i] == '<' && line[i + 1] == '<')
		{
			new[j++] = ' ';
			new[j++] = line[i++];
			new[j++] = line[i++];
			new[j++] = ' ';
		}
		else if (line[i] == '>' || line[i] == '<')
		{
			new[j++] = ' ';
			new[j++] = line[i++];
			new[j++] = ' ';
		}
		else
			new[j++] = line[i++];
	}
	new[j] = '\0';
	ft_chng_c(new, ' ');
	free(line);
	return (new);
}

t_cmd    *ft_getcmd(char **full_cmd, char **env)
{
	t_cmd	*cmd;
	char    **token;
	int     i;

	cmd = malloc(ft_dblen(full_cmd) * sizeof(t_cmd));
	ft_init_cmd(cmd, ft_dblen(full_cmd), env);
	i = 0;
	while (full_cmd[i])
	{
		ft_chng_c(full_cmd[i], ' ');
		token = ft_split(ft_add_space(full_cmd[i]), -1);
		ft_parse_cmd(&cmd[i], token, env);
		free(token);
		i++;
	}
	full_cmd[i] = NULL;
	return (cmd);
}
