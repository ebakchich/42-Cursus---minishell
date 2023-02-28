/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:07:12 by yoyahya           #+#    #+#             */
/*   Updated: 2023/02/28 16:02:08 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	joinenv3(t_var **var, char *vale, char *val, int pos)
{
	vale = ft_strdup((*var)->env[pos]);
	val = ft_strjoin(vale, delchar(val, '='));
	free((*var)->env[pos]);
	(*var)->env[pos] = val;
	return (0);
}

int	joinenv2(t_var **var, char *cmd, char *val, int pos)
{
	char	*namee;
	char	*vale;
	char	*tmp;

	namee = ft_strchr((*var)->env[pos], '=');
	if (val && !namee)
	{
		vale = ft_strdup((*var)->env[pos]);
		tmp = ft_strdup(val);
		free(val);
		val = ft_strjoin_3(vale, tmp);
		free(tmp);
		free((*var)->env[pos]);
		(*var)->env[pos] = ft_strdup(val);
		free(val);
		free(vale);
		return (0);
	}
	return (joinenv3(var, vale, val, pos));
}

int	ft_export2(t_var *var, char *cmd, int flag)
{
	int		pos;
	int		len;
	char	*tmp;

	pos = 0;
	len = len_matrix(var->env);
	if (flag == 1)
		joinenv(&var, cmd);
	else if (findenv(var, cmd, &pos) == 0)
	{
		tmp = ft_strchr(cmd, '=');
		if (!tmp)
			return (0);
		else
			repenv(var, ft_strdup(cmd), pos);
	}
	else if (findenv(var, cmd, &pos) == 1)
		appenv(&var, ft_strdup(cmd));
	return (0);
}
