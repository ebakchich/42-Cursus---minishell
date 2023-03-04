/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 06:18:50 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/04 10:15:29 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_join_all(char **ex)
{
	char	*line;
	int		i;

	line = ft_strdup("");
	i = 0;
	while (ex[i])
	{
		if (ex[i][0] != -1)
			line = ft_strjoin(line, ex[i]);
		i++;
	}
	return (line);
}

char	*ft_get_env2(char *line)
{
	char	**ex;
	char	*tmp;
	int		i;

	ex = ft_split(line, '$');
	i = 0;
	while (ex[i])
	{
		tmp = ex[i];
		ex[i] = ft_strdup(get_env(g_ex.var->env, ex[i]));
		free(tmp);
		i++;
	}
	free(line);
	line = ft_join_all(ex);
	ft_free(NULL, ex);
	return (line);
}

char	*ft_get_env(char *line)
{
	char	**ex;
	int		i;

	line = ft_check_sp(line);
	ex = ft_split(line, -1);
	i = 0;
	while (ex[i])
	{
		if (ft_count_c(ex[i], '$'))
			ex[i] = ft_get_env2(ex[i]);
		i++;
	}
	free(line);
	line = ft_join_all(ex);
	ft_free(NULL, ex);
	return (line);
}

char	*ft_check_n(char *line)
{
	char	**ex;
	int		i;

	line = add_befor_c(line, 10);
	ex = ft_split(line, -1);
	free(line);
	i = 0;
	while (ex[i])
	{
		if (ft_count_c(ex[i], 36))
			ex[i] = ft_get_env(ex[i]);
		i++;
	}
	line = ft_join_all(ex);
	ft_free(NULL, ex);
	return (line);
}

char	*ft_expend(char *line)
{
	char	**s;
	int		i;

	if (ft_count_c(line, ' '))
	{
		line = add_befor_c(line, ' ');
		s = ft_split(line, -1);
		i = 0;
		while (s[i])
		{
			if (ft_count_c(s[i], 36))
				s[i] = ft_check_n(s[i]);
			i++;
		}
		line = ft_join_all(s);
		ft_free(NULL, s);
	}
	else if (ft_count_c(line, 10))
		line = ft_check_n(line);
	else if (ft_count_c(line, 36))
		line = ft_get_env(line);
	return (line);
}
