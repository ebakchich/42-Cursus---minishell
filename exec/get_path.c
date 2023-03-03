/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:04:15 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/03 18:35:47 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_3(char *s1, char *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = ft_calloc(lens1 + lens2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, lens1);
	ft_memmove(str + lens1, s2, lens2);
	str[lens1 + lens2 + 1] = '\0';
	return (str);
}

char	*get_path(t_var *var, t_cmd *cmd)
{
	int		i;
	char	**path;
	char	*tmp;
	char	*command;

	i = -1;
	while (var->env[++i] && ft_strncmp(var->env[i], "PATH=", 5) != 0)
		;
	if (var->env[i] == NULL)
		return (NULL);
	path = ft_split(var->env[i] + 5, ':');
	i = -1;
	while (path && path[++i])
	{
		tmp = ft_strjoin_3(path[i], "/");
		command = ft_strjoin(tmp, cmd->cmd[0]);
		if (access(command, F_OK | X_OK) == 0)
		{
			free_matrix(path);
			return (command);
		}
		free(command);
	}
	free_matrix(path);
	return (NULL);
}
