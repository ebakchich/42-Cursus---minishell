/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:45:58 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/02 13:02:24 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	herdoc(t_cmd data)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		perror("minishell");
		return ;
	}
	write(fd[1], data.her, ft_strlen(data.her));
	dup2(fd[0], 0);
	close(fd[1]);
}

int	ft_exec(t_var *data, t_cmd *cmd)
{
	int	i;
	int	status;
	int	ncmd;
	int	pip_in;

	pip_in = STDIN_FILENO;
	i = -1;
	if (!data || !cmd)
		return (0);
	ncmd = cmd[0].num_pip;
	if (cmd[0].if_v != -1 && ncmd == 1 && is_builtin(cmd[0].cmd[0]))
		return (sel_builtin(cmd, data, 1));
	else if (cmd[0].if_v != -1 && ncmd == 1 && !is_builtin(cmd[0].cmd[0]))
		return (sin_cmd(data, cmd));
	while (++i < ncmd)
	{
		if(cmd[i].if_v != -1)
			pip_in = mult_cmd(&cmd[i], data, pip_in, i);
	}
	i = -1;
	while (++i < ncmd)
		wait(&status);
	sel_builtin(cmd, data, 0);
	return (status);
}
