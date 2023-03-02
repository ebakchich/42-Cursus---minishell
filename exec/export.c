/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:07:12 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/02 18:49:53 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	joinenv(t_var **var, char *cmd)
{
	int		pos;
	char	*val;

	pos = 0;
	val = get_val(cmd, 1);
	if (!val || !cmd)
	{
		free(val);
		return (1);
	}
	if (findenv(*var, cmd, &pos) == 0)
		joinenv2(var, val, pos);
	else
	{
		free(val);
		appenv(var, ft_strdup(delchar(cmd, '+')));
	}
	return (0);
}

int	repenv(t_var *data, char *var, int pos)
{
	char	**nenv;
	int		i;
	int		j;
	int		len;

	len = len_matrix(data->env);
	i = 0;
	j = 0;
	nenv = malloc(sizeof(char *) * len + 1);
	while (i < len)
	{
		if (pos == i)
		{
			nenv[i++] = ft_strdup(var);
			j++;
		}
		nenv[i] = ft_strdup(data->env[j]);
		i++;
		j++;
	}
	nenv[i] = NULL;
	free_matrix(data->env);
	free(var);
	data->env = nenv;
	return (0);
}

int	appenv(t_var **data, char *var)
{
	char	**nenv;
	int		i;
	int		len;

	i = 0;
	len = len_matrix((*data)->env);
	nenv = malloc(sizeof(char *) * (len + 2));
	if (!nenv)
		return (err_alloc("malloc"));
	while (i < len)
	{
		nenv[i] = ft_strdup((*data)->env[i]);
		if (!nenv[i])
			return (err_alloc("strjoin1"));
		i++;
	}
	nenv[i] = ft_strdup(var);
	if (!nenv[i])
		return (err_alloc("strjoin1"));
	nenv[i + 1] = NULL;
	free_matrix((*data)->env);
	(*data)->env = nenv;
	free(var);
	return (0);
}

int	ft_export(t_var *var, char **cmd)
{
	int		i;
	int		flag;

	flag = 0;
	if (!var || !var->env)
	{
		perror("minishell");
		return (1);
	}
	if (!cmd[1])
		return (printenv(var->env));
	i = 1;
	while (cmd && cmd[i])
	{
		if (valexp(var->env, cmd[i], &flag) == 1)
			export_err(cmd[i], 1);
		else
			ft_export2(var, cmd[i], flag);
		i++;
	}
	return (0);
}
