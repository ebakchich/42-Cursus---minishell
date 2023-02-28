/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:46:29 by yoyahya           #+#    #+#             */
/*   Updated: 2023/02/28 09:13:15 by yoyahya          ###   ########.fr       */
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
			if ((cmd[i][j] < 48 || cmd[i][j] > 57) && cmd[i][j] > 0)
				count++;
			j++;
		}
		if (cmd[i][0] == -1)
			cmd[i][0] = '-';
		i++;
	}
	if (count == (i - 1))
	{
		printf("numeric argument required\n");
		exit (255);
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
	printf("too many arguments\n");
}
