/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:37:59 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/04 05:04:40 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_file(t_cmd *cmd, char **token)
{
	int	l;

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
	size_t	len;
	int		i;

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
	int		i;
	int		c;
	int		l;

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
				cmd[c] = ft_before_expend(cmd[c], 1);
			if (ft_count_c(cmd[c], 34) || ft_count_c(cmd[c], 39))
				cmd[c] = ft_remove_db(cmd[c], 1);
			c++;
		}
		i++;
	}
	cmd[c] = NULL;
}

void	ft_check_in(t_cmd *cmd, char **token)
{
	int		i;
	char	*tmp;

	i = 0;
	while (token[i])
	{
		if (ft_memcmp(token[i], "<<", 2) == 0)
			tmp = token[i];
		else if (ft_memcmp(token[i], "<", 1) == 0)
			tmp = token[i];
		i++;
	}
	if (ft_memcmp(tmp, "<<", 2) == 0)
		cmd->infile = -1;
}

void	ft_parse_cmd(t_cmd *cmd, char **token, int count)
{
	char	**dr;
	int		i;
	size_t	l;

	ft_check_her(cmd, token, 0);
	ft_check_file(cmd, token);
	ft_check_in(cmd, token);
	dr = ft_split(">> << < >", ' ');
	l = 0;
	while (token[l])
		l++;
	i = 0;
	while (dr[i])
	{
		count = ft_count_str(token, dr[i]);
		l = l - (count * 2);
		i++;
	}
	if (l != 0)
	{
		cmd->cmd = malloc((l + 1) * sizeof(char *));
		ft_full_cmd(token, cmd->cmd, dr);
	}
	ft_free(NULL, dr);
}
