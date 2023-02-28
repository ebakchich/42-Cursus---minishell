/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:59:38 by yoyahya           #+#    #+#             */
/*   Updated: 2023/02/27 18:59:55 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(void)
{
	char	pwd[PATH_MAX];
	int		len;

	len = 0;
	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		ft_putendl_fd("minishell: error in getcwd", 2);
		return (1);
	}
	len = ft_strlen(pwd);
	pwd[len++] = '\n';
	write(1, pwd, len++);
	return (0);
}
