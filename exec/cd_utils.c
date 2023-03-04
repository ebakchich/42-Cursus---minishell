/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:10:17 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/04 07:50:10 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd_err(char *str, int flag)
{
	if (flag == 1)
		ft_putendl_fd("minishell: cd: to many argument", 2);
	else if (flag == 2)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else if (flag == 3)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": not set", 2);
	}
	else if (flag == 4)
		ft_putendl_fd("minishell: error in getcwd", 2);
	return (1);
}

int	check_exist(char **env, char *str)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str)) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	updpwd(t_var *data)
{
	char	*oldpwd;
	int		i;
	char	pwd[PATH_MAX];
	int		len;

	i = 0;
	len = len_matrix(data->env);
	if (getcwd(pwd, PATH_MAX) == NULL)
		return (cd_err(NULL, 4));
	oldpwd = ft_strjoin(ft_strdup("OLDPWD="), pwd);
	if (!oldpwd)
		return (unset_err(NULL, 2));
	if (findenv(data, "OLDPWD=", &i) == 0)
		repenv(data, oldpwd, i, len);
	else
		appenv(&data, oldpwd);
	if (chdir(pwd) == -1)
		return (cd_err(pwd, 2));
	return (0);
}

int	update(t_var **data, char *old)
{
	char	pwd[PATH_MAX];
	int		i;
	char	*tmp;
	int		len;

	i = 0;
	len = len_matrix((*data)->env);
	if (!data)
		return (0);
	getcwd(pwd, PATH_MAX);
	tmp = ft_strjoin(ft_strdup("PWD="), pwd);
	if (findenv(*data, "PWD=", &i) == 0)
		repenv(*data, tmp, i, len);
	else
		appenv(data, tmp);
	i = 0;
	tmp = ft_strjoin(ft_strdup("OLDPWD="), old);
	if (findenv(*data, "OLDPWD=", &i) == 0)
		repenv(*data, tmp, i, len);
	else
		appenv(data, tmp);
	return (0);
}
