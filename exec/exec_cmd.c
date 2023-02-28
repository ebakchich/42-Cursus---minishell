/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:44:13 by yoyahya           #+#    #+#             */
/*   Updated: 2023/02/28 14:15:15 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_cmd(t_cmd *cmd, t_var *var)
{
	char	*command;

	if (ft_strchr(cmd[0].cmd[0], '/') != NULL)
	{
		if (execve(cmd[0].cmd[0], cmd[0].cmd, var->env) == -1)
		{
			perror("minishell");
			exit(127);
		}
	}
	command = get_path(var, cmd);
	if (!command)
	{
		perror("minishell");
		exit(127);
	}
	if (execve(command, cmd[0].cmd, var->env) == -1)
	{
		perror("minishell:");
		exit(126);
	}
	return (0);
}

int	sin_cmd(t_var *data, t_cmd *cmd)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Error :");
		return (1);
	}
	else if (pid == 0)
	{
		rid(*cmd);
		exec_cmd(cmd, data);
	}
	waitpid(pid, NULL, 0);
	return (0);
}

void	rid(t_cmd data)
{
	if (data.infile != -1)
		dup2(data.infile, 0);
	if (data.outfile != -1)
		dup2(data.outfile, 1);
}

void	child_proc(t_cmd *cmd, t_var *var, int *pip, int *pip_i)
{
	close(pip[0]);
	if (cmd->infile != -1)
		dup2(cmd->infile, 0);
	else
		dup2(pip_i[0], 0);
	if (cmd->outfile != -1)
		dup2(cmd->outfile, 1);
	if (pip_i[1] + 1 >= cmd->num_pip)
		close(pip[1]);
	else
		dup2(pip[1], 1);
	if (cmd->cmd[0] && !is_builtin(cmd->cmd[0]))
		exec_cmd(cmd, var);
	else
		builtin(cmd, var, 1);
	exit(0);
}

int	mult_cmd(t_cmd *cmd, t_var *var, int pip_in, int i)
{
	int		pip[2];
	pid_t	pid;
	int		pip_i[2];

	if (pipe(pip))
		perror("minishell:");
	pid = fork();
	if (pid == -1)
	{
		perror("minishell:");
		return (1);
	}
	if (pid == 0)
	{
		pip_i[0] = pip_in;
		pip_i[1] = i;
		child_proc(cmd, var, pip, pip_i);
	}
	if (i != 0)
		close(pip_in);
	close(pip[1]);
	return (pip[0]);
}
