/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:37:59 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/11 17:26:37 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_get_fd(int *fd, char **token, char *str)
{
	int i;
	int d;
	int f;

	i = 0;
	d = 0;
	while (token[i])
	{
		if (ft_memcmp(token[i], str, ft_strlen(str)) == 0)
		{
			f = open(token[i + 1], O_CREAT);
			fd[d] = f;
			d++;
		}
		i++;
	}
}

void    ft_check_file(t_cmd *cmd, char **token)
{
	int l;

	l = ft_count_str(token, "<");
	if (l != 0)
	{
		cmd->infile = malloc(l * sizeof(int));
		ft_get_fd(cmd->infile, token, "<");
	}
	l = ft_count_str(token, ">");
	if (l != 0)
	{
		cmd->outfile = malloc(l * sizeof(int *));
		ft_get_fd(cmd->outfile, token, ">");
	}
	l = ft_count_str(token, ">>");
	if (l != 0)
	{
		cmd->apend = malloc(l * sizeof(int *));
		ft_get_fd(cmd->apend, token, ">>");
	}
}

void	ft_full_cmd(char **token, char **cmd)
{
	int	i;

	i = 0;
	while (token[i])
	{
		i++;
	}
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
		ft_full_cmd(token, cmd->cmd);
	}
}
