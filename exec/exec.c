/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:45:58 by yoyahya           #+#    #+#             */
/*   Updated: 2023/02/28 10:00:10 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_exec(t_var *data, t_cmd *cmd)
{
	int	i;
	int	status;
	int	ncmd;
	int	pip_in;

	pip_in = STDIN_FILENO;
	i = -1;
	if (!data || !cmd || !cmd[0].cmd)
		return (0);
	ncmd = cmd[0].num_pip;
	if (ncmd == 1 && is_builtin(cmd[0].cmd[0]))
		return (sel_builtin(cmd, data));
	else if (cmd[0].if_v && ncmd == 0 && !is_builtin(cmd[0].cmd[0]))
		return (sin_cmd(data, cmd));
	while (++i < ncmd && cmd[i].cmd)
		pip_in = mult_cmd(&cmd[i], data, pip_in, i);
	i = -1;
	while (++i < ncmd)
		wait(&status);
	return (status);
}
