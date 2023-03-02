/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:44:13 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/02 16:37:06 by ebakchic         ###   ########.fr       */
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
	int	status;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid < 0)
	{
		perror("Error :");
		return (1);
	}
	else if (pid == 0)
	{
		signal(SIGQUIT, signal_handler_ch);
		signal(SIGINT, signal_handler_ch);
		rid(*cmd);
		exec_cmd(cmd, data);
	}
	waitpid(pid, &status, 0);
	g_ex.exit_status = WEXITSTATUS(status);
	if (status == 2)
		g_ex.exit_status = 130;
	if (status == 3)
		g_ex.exit_status = 131;
	return (0);
}

void	rid(t_cmd data)
{
	if (data.her && data.her[0])
		herdoc(data);
	if (data.infile != -1)
	{
		write(2, "werfhdnk\n", 9);
		dup2(data.infile, 0);
	}
	if (data.outfile != -1)
	{
		write(2, "qwertyuiop\n", 10);
		dup2(data.outfile, 1);
	}
	if (data.apend != -1)
	{
		write(2, "zzzzzzzzz\n", 10);
		dup2(data.apend, 1);
	}
}

void	child_proc(t_cmd *cmd, t_var *var, int *pip, int *pip_i)
{
	close(pip[0]);
	if (cmd->her && cmd->her[0])
		herdoc(*cmd);
	if (cmd->infile != -1)
		dup2(cmd->infile, 0);
	else
		dup2(pip_i[0], 0);
	if (cmd->apend != -1)
		dup2(cmd->apend, 1);
	if (cmd->outfile != -1)
		dup2(cmd->outfile, 1);
	if (pip_i[1] + 1 >= cmd->num_pip)
		close(pip[1]);
	else if (cmd->outfile == -1)
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

	if (pipe(pip) == -1)
		return (perror("minishell:"), 1);
	pid = fork();
	g_ex.id = pid;
	if (pid == -1)
	{
		perror("minishell:");
		return (1);
	}
	if (pid == 0)
	{
		signal(SIGINT, signal_handler_ch);
		pip_i[0] = pip_in;
		pip_i[1] = i;
		child_proc(cmd, var, pip, pip_i);
	}
	if (i != 0)
		close(pip_in);
	close(pip[1]);
	return (pip[0]);
}