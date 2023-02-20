/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:13:31 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/20 17:40:35 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char *p, char **p2)
{
	int	i;

	i = 0;
	i = 0;
	if (p2 != NULL)
	{
		while (p2[i])
		{
			free(p2[i]);
			i++;
		}
		free(p2);
	}
	if (p != NULL)
		free(p);
}

void	ft_free_cmd(t_cmd *cmd)
{
	int	i;
	int	num_pip;

	num_pip = cmd[0].num_pip;
	i = 0;
	while (i < num_pip)
	{
		ft_free(cmd[i].her, cmd[i].cmd);
		i++;
	}
	free(cmd);
}
