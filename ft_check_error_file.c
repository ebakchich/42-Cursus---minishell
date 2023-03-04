/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:15:37 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/04 03:17:09 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_error_file2(char *name, t_cmd *cmd)
{
	if (access(name, F_OK) != -1)
	{
		if (access(name, W_OK) == -1)
		{
			cmd->if_v = -1;
			g_ex.exit_status = 1;
			write(2, "Error: permission denied\n", 25);
			return (0);
		}
	}
	return (1);
}

int	ft_check_error_file(char *name, int j, t_cmd *cmd)
{
	if (j == 1)
	{
		if (access(name, F_OK) == -1)
		{
			cmd->if_v = -1;
			g_ex.exit_status = 1;
			write(2, "Error: No such file or directory ", 32);
			printf("%s\n", name);
			return (0);
		}
		if (access(name, R_OK) == -1)
		{
			cmd->if_v = -1;
			g_ex.exit_status = 1;
			write(2, "Error: permission denied\n", 25);
			return (0);
		}
	}
	else
		return (ft_check_error_file2(name, cmd));
	return (1);
}

int	ft_check_ambiguous(char *line, int i)
{
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (1);
	}
	while (line[i] && line[i] != ' ')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (0);
	}
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] != '\0')
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

char	*ft_get_fd2(t_cmd *cmd, char *t, int j)
{
	if (ft_count_c(t, 36))
		t = ft_before_expend(t, 1);
	if (ft_count_c(t, 34) || ft_count_c(t, 39))
		t = ft_remove_db(t, 1);
	if (t[0] == '\0')
	{
		cmd->if_v = -1;
		g_ex.exit_status = 1;
		printf("no such file or directory:\n");
	}
	else if (ft_check_error_file(t, j, cmd))
	{
		if (j == 1)
			cmd->infile = open(t, O_RDONLY);
		else if (j == 2)
			cmd->outfile = open(t, O_CREAT
					| O_WRONLY | O_TRUNC, 0644);
		else if (j == 3)
			cmd->apend = open(t, O_CREAT
					| O_WRONLY | O_APPEND, 0644);
	}
	return (t);
}

void	ft_get_fd(t_cmd *cmd, char **t, char *str, int j)
{
	char	*ptr;
	size_t	len;
	int		i;

	i = 0;
	while (t[i])
	{
		len = ft_strlen(str);
		if (len < ft_strlen(t[i]))
			len = ft_strlen(t[i]);
		if (ft_memcmp(t[i], str, len) == 0)
		{
			ptr = ft_strdup(t[i + 1]);
			ptr = ft_before_expend(ptr, 1);
			if (ft_check_ambiguous(ptr, 0) && ft_count_c(t[i + 1], '$'))
			{
				cmd->if_v = -1;
				g_ex.exit_status = 1;
				printf("%s: ambiguous redirect\n", t[i + 1]);
			}			
			else
				t[i + 1] = ft_get_fd2(cmd, t[i + 1], j);
		}
		i++;
	}
}
