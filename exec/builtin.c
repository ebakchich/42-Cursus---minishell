/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:24:18 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/02 17:53:39 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	sel_builtin(t_cmd *cmd, t_var *data, int flag)
{
	int	original;
	int	ginal;

	original = dup(1);
	ginal = dup(0);
	if (flag == 1)
	{
		rid(*cmd);
		builtin(cmd, data, 0);
	}
	dup2(original, 1);
	dup2(ginal, 0);
	return (0);
}

int	builtin(t_cmd *cmd, t_var *var, int fork)
{
	if (ft_strncmp(cmd[0].cmd[0], "pwd", 3) == 0 \
									&& ft_strlen(cmd[0].cmd[0]) == 3)
		g_ex.exit_status = ft_pwd();
	else if (ft_strncmp(cmd[0].cmd[0], "echo", 4) == 0 \
									&& ft_strlen(cmd[0].cmd[0]) == 4)
		g_ex.exit_status = echo(cmd[0].cmd);
	else if (ft_strncmp(cmd[0].cmd[0], "unset", 5) == 0 \
									&& ft_strlen(cmd[0].cmd[0]) == 5)
		g_ex.exit_status = unset(var, cmd[0].cmd);
	else if (ft_strncmp(cmd[0].cmd[0], "cd", 2) == 0 \
									&& ft_strlen(cmd[0].cmd[0]) == 2)
		g_ex.exit_status = cd(cmd[0].cmd, var);
	else if (ft_strncmp(cmd[0].cmd[0], "export", 6) == 0 \
									&& ft_strlen(cmd[0].cmd[0]) == 6)
		g_ex.exit_status = ft_export(var, cmd->cmd);
	else if (ft_strncmp(cmd[0].cmd[0], "exit", 4) == 0 \
									&& ft_strlen(cmd[0].cmd[0]) == 4)
		ft_exit(cmd);
	else if (ft_strncmp(cmd[0].cmd[0], "env", 3) == 0 \
									&& ft_strlen(cmd[0].cmd[0]) == 3)
		g_ex.exit_status = env(var->env);
	if (fork == 1)
		exit(g_ex.exit_status);
	return (1);
}
