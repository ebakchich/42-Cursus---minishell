/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:46:29 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/02 13:44:05 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error(char **cmd)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 1;
	while (cmd[i])
	{
		j = 0;
		if (cmd[i][0] == '+')
			cmd[i][0] = '0';
		if (cmd[i][0] == '-')
			cmd[i][0] = -1;
		while (cmd[i][j])
		{
			if ((cmd[i][j] < 48 || cmd[i][j] > 57) && cmd[i][j] > 0 && i == 1)
			{
				printf("exit\nminishell: exit: %s: numeric argument required\n", cmd[i]);
				exit (255);
			}
			j++;
		}
		if (cmd[i][0] == -1)
			cmd[i][0] = '-';
		i++;
	}
}

void	ft_error2(char **cmd)
{
	if (ft_atoi(cmd[1]) >= 0)
		exit (ft_atoi(cmd[1]));
	exit ((-256 + ft_atoi(cmd[1])) + 256);
}

void	ft_exit(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd[0].cmd[i])
		i++;
	if (i == 1)
		exit (0);
	ft_error(cmd[0].cmd);
	if (i == 2)
		ft_error2(cmd[0].cmd);
	printf("minishell: exit: too many arguments\n");
	g_ex.exit_status = 1;
}
