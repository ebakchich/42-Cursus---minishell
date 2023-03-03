/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:01:33 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/03 20:42:50 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**remenv(char **env, int pos, int len)
{
	char	**nenv;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nenv = malloc(sizeof(char *) * len);
	if (!nenv)
		return (0);
	while (i < (len - 1))
	{
		if (i == pos)
			j++;
		nenv[i] = ft_strdup(env[j]);
		if (!nenv[i])
		{
			free_matrix(nenv);
			return (0);
		}
		i++;
		j++;
	}
	nenv[i] = NULL;
	return (nenv);
}

int	unset(t_var *data, char **cmd)
{
	int		lenx;
	int		pos;
	char	**nenv;
	int		i;
	int		status;

	i = 0;
	pos = 0;
	status = 0;
	nenv = NULL;
	while (cmd && cmd[++i])
	{
		lenx = len_matrix(data->env);
		if (cmd[i] && is_valid(cmd[i]) != 0)
			status = unset_err(cmd[i], 1);
		else if (findenv(data, cmd[i], &pos) == 0)
		{
			nenv = remenv(data->env, pos, lenx);
			if (!nenv)
				return (unset_err(NULL, 2));
			free_matrix(data->env);
			data->env = nenv;
		}
	}
	return (status);
}
