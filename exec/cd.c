/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:10:14 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/03 20:09:03 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env(char **env, char *line)
{
	int		i;
	char	*tmp;
	int		count;

	i = 0;
	count = ft_strlen(line);
	while (env[i])
	{
		if (ft_strncmp(line, env[i], ft_strlen(line)) == 0
			&& env[i][count] == '=')
		{
			tmp = ft_strchr(env[i], '=');
			return (tmp + 1);
		}
		i++;
	}
	return (NULL);
}

int	cd_1(t_var *data)
{
	char	*oldpwd;

	if (!data || !data->env)
		return (0);
	oldpwd = get_env(data->env, "OLDPWD");
	if (!oldpwd)
		return (cd_err("OLDPWD", 3));
	if (chdir(oldpwd) == -1)
		return (cd_err(oldpwd, 2));
	else
		ft_pwd();
	return (0);
}

int	cd(char **cmd, t_var *data)
{
	int		i;
	char	old[PATH_MAX];

	i = 0;
	getcwd(old, PATH_MAX);
	if (!cmd[1])
	{
		if (chdir(get_env(data->env, "HOME")) == -1)
			return (cd_err("HOME", 3));
		return (update(&data, old));
	}
	else if (ft_strncmp(cmd[1], "-", ft_strlen(cmd[1])) == 0)
	{
		cd_1(data);
		return (update(&data, old));
	}
	else if (chdir(cmd[1]) == -1)
	{
		perror("minishell");
		return (1);
	}
	return (update(&data, old));
}
