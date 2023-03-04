/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:53:29 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/04 05:05:12 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_dblen(char **full_cmd)
{
	int	i;

	i = 0;
	while (full_cmd[i])
		i++;
	return (i);
}

void	ft_init_cmd(t_cmd *cmd, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		cmd[i].if_v = 0;
		cmd[i].num_pip = x;
		cmd[i].cmd = NULL;
		cmd[i].infile = -1;
		cmd[i].outfile = -1;
		cmd[i].her = NULL;
		cmd[i].apend = -1;
		i++;
	}
}

int	ft_count_red(char *line)
{
	int	i;
	int	count;

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

char	*ft_add_space(char *line, int i, int j, int count)
{
	char	*new;

	new = malloc((ft_strlen(line) + (count * 2) + 1) * sizeof(char));
	while (line[i])
	{
		if ((line[i] == '>' && line[i + 1] == '>')
			|| (line[i] == '<' && line[i + 1] == '<'))
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
	return (new);
}

t_cmd	*ft_getcmd(char **full_cmd)
{
	int		count;
	char	*tmp;
	t_cmd	*cmd;
	char	**token;
	int		i;

	cmd = malloc(ft_dblen(full_cmd) * sizeof(t_cmd));
	ft_init_cmd(cmd, ft_dblen(full_cmd));
	i = 0;
	while (full_cmd[i])
	{
		ft_chng_c(full_cmd[i], ' ');
		count = ft_count_red(full_cmd[i]);
		if (count != 0)
			tmp = ft_add_space(full_cmd[i], 0, 0, count);
		else
			tmp = full_cmd[i];
		token = ft_split(tmp, -1);
		if (count != 0)
			free(tmp);
		ft_parse_cmd(&cmd[i], token, 0);
		i++;
		ft_free(NULL, token);
	}
	return (cmd);
}
