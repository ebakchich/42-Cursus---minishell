/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:00:08 by yoyahya           #+#    #+#             */
/*   Updated: 2023/02/27 19:00:33 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char *cmd)
{
	int	len;

	len = ft_strlen(cmd);
	if (ft_strchr(cmd, '/'))
		return (0);
	else if (!ft_strncmp(cmd, "cd", len) && len == 2)
		return (1);
	else if (!ft_strncmp(cmd, "echo", len) && len == 4)
		return (1);
	else if (!ft_strncmp(cmd, "pwd", len) && len == 3)
		return (1);
	else if (!ft_strncmp(cmd, "exit", len) && len == 4)
		return (1);
	else if (!ft_strncmp(cmd, "env", len) && len == 3)
		return (1);
	else if (!ft_strncmp(cmd, "export", len) && len == 6)
		return (1);
	else if (!ft_strncmp(cmd, "unset", len) && len == 5)
		return (1);
	else
		return (0);
}
