/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:58:40 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/04 06:05:23 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	len_matrix(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

char	**dup_matrix(char **env)
{
	int		i;
	int		len;
	char	**nenv;

	i = 0;
	len = len_matrix(env);
	nenv = malloc(sizeof(char *) * (len + 1));
	if (!nenv)
	{
		perror("minishell");
		return (NULL);
	}
	while (env[i])
	{
		nenv[i] = ft_strdup(env[i]);
		if (!nenv[i])
		{
			free_matrix(nenv);
			return (NULL);
		}
		i++;
	}
	nenv[i] = NULL;
	return (nenv);
}

int	err_alloc(char *str)
{
	ft_putstr_fd("minishell: error allocation in ", 2);
	ft_putendl_fd(str, 2);
	return (1);
}

char	*delchar(char *cmd, char c)
{
	int	i;

	i = 0;
	if (!cmd || !*cmd)
		return (0);
	while (cmd[i] != c)
		i++;
	ft_memmove(&cmd[i], &cmd[i + 1], ft_strlen(cmd) - i);
	return (cmd);
}
