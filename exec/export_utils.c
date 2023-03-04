/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:47:53 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/04 07:21:30 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	valexp(char **env, char *var, int *flag)
{
	int	i;

	i = 0;
	if (!env || !var[0])
		return (1);
	while (var[i])
	{
		if (i != 0 && var[i] == '+' && var[i + 1] == '=')
		{
			*flag = 1;
			return (0);
		}
		if (i != 0 && var[i] == '=')
			return (0);
		else if (i == 0 && !ft_isalpha(var[i]) && var[i] != '_')
			return (1);
		else if (i != 0 && !ft_isalnum(var[i]) && var[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

char	**sort(char **env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (env[i])
	{
		j = i + 1;
		while (env[j])
		{
			if (ft_strcmp(env[i], env[j]) > 0)
			{
				tmp = env[i];
				env[i] = env[j];
				env[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (env);
}

int	export_err(char *str, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	else if (flag == 2)
		ft_putendl_fd("minishell: Error in malloc", 2);
	else if (flag == 3)
	{
		free(str);
		ft_putendl_fd("minishell: Error in malloc", 2);
	}
	return (1);
}

void	print_sort(char **dup, int j, int i, char *tmp)
{
	while (dup && dup[i])
	{
		if (dup[i][j] && dup[i][j] != '=')
			printf("declare -x ");
		while (dup[i][j] && dup[i][j] != '=')
		{
			printf("%c", dup[i][j]);
			j++;
		}
		tmp = ft_strchr(dup[i], '=');
		if (tmp)
		{
			printf("=\"");
			printf("%s\"", ++tmp);
		}
		if (j != 0)
			printf("\n");
		j = 0;
		i++;
	}
}

int	printenv(char **env)
{
	char	**dup;
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	if (!env)
		return (1);
	dup = dup_matrix(env);
	dup = sort(dup);
	if (dup && dup[0])
		print_sort(dup, j, i, tmp);
	free_matrix(dup);
	return (0);
}
