/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:37:59 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/21 17:16:14 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_ambiguous(char *line)
{
	int	i;

	if (ft_count_c(line, 36) == 0)
		return (0);
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (1);
	while (line[i] && line[i] != ' ')
		i++;
	if (line[i] == '\0')
		return (0);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] != '\0')
		return (1);
	return (0);
}

void    ft_get_fd(t_cmd *cmd, char **token, char *str, int j)
{
	char	*ptr;
	int i;
	int f;

	i = 0;
	while (token[i])
	{
		if (ft_memcmp(token[i], str, ft_strlen(str)) == 0)
		{
			ptr = ft_strdup(token[i + 1]);
			ptr = ft_expend(ptr);
			if (ft_check_ambiguous(ptr) && ft_ex_c(token[i + 1]) != 39)
				printf("%s: ambiguous redirect\n", token[i + 1]);
			else
			{
				
				if (ft_count_c(token[i + 1], 36) && ft_ex_c(token[i + 1]) != 39)
					token[i + 1] = ft_expend(token[i + 1]);
				if (ft_count_c(token[i + 1], 34) || ft_count_c(token[i + 1], 39))
					token[i + 1] = ft_remove_db(token[i + 1]);
				if (ft_check_error_file(token[i + 1], j, &cmd->if_v))
				{
					if (j == 1)
						cmd->infile = open(token[i + 1], O_RDONLY);
					else if (j == 2)
						cmd->outfile = open(token[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
					else if (j == 3)
						cmd->apend = open(token[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
				}
			}
		}
		i++;
	}
	free(ptr);
}

void    ft_check_file(t_cmd *cmd, char **token)
{
	int l;

	l = ft_count_str(token, "<");
	if (l != 0)
		ft_get_fd(cmd, token, "<", 1);
	l = ft_count_str(token, ">");
	if (l != 0)
		ft_get_fd(cmd, token, ">", 2);
	l = ft_count_str(token, ">>");
	if (l != 0)
		ft_get_fd(cmd, token, ">>", 3);
}

int	ft_if_red(char *token, char **dr)
{
	int	len;
	int	i;

	i = 0;
	while (dr[i])
	{
		len = ft_strlen(dr[i]);
		if (len < ft_strlen(token))
			len = ft_strlen(token);
		if (ft_memcmp(token, dr[i], len) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_full_cmd(char **token, char **cmd, char **dr)
{
	int	i;
	int	c;
	int	l;

	l = 0;
	while (token[l])
		l++;
	i = 0;
	c = 0;
	while (i < l)
	{
		if (ft_if_red(token[i], dr))
			i = i + 1;
		else
		{
			cmd[c] = ft_strdup(token[i]);
			if (ft_count_c(cmd[c], '$'))
				cmd[c] = ft_expend(cmd[c]);
			if (ft_count_c(cmd[c], 34) || ft_count_c(cmd[c], 39))
				cmd[c] = ft_remove_db(cmd[c]);
			c++;
		}
		i++;
	}
	cmd[c] = NULL;
}

void    ft_parse_cmd(t_cmd *cmd, char **token, char **env)
{
	char	**dr;
	int i;
	int	l;

	int test = 0;

	ft_check_her(cmd, token);
	ft_check_file(cmd, token);
	dr = ft_split(">> << < >", ' ');
	l = 0;
	while (token[l])
		l++;
	i = 0;
	while (dr[i])
	{
		test = ft_count_str(token, dr[i]);
		l = l - (test * 2);
		i++;
	}
	if (l != 0)
	{
		cmd->cmd = malloc((l + 1) * sizeof(char *));
		ft_full_cmd(token, cmd->cmd, dr);
	}
	ft_free(NULL, dr);
}
