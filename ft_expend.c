/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 06:18:50 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/13 16:42:36 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_env(char *line)
{
	char	**ex;
	char	**env;
	int		check;
	int	i;

	check = 0;
	ex = ft_split(line, 36);
	i = 0;
	while (ex[i])
		i++;
	env = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (ex[i])
	{
		if (ft_count_c(ex[i], 10))
		{
			check++;
			ex[i][ft_strlen(ex[i]) - 1] = '\0';
		}
		printf("line = %s\n", ex[i]);
		env[i] = getenv(ex[i]);
		//printf("line = %s\n", env[i]);
		i++;
	}
	env[i] = NULL;
	i = 0;
	line = ft_strdup("");
	while (env[i])
	{
		line = ft_strjoin(line, env[i]);
		i++;
	}
	if (check)
		line = ft_strjoin(line, "\n");
	return (line);
}

char	*ft_check_n(char *line)
{
	char	**ex;
	int	i;
	
	if (ft_count_c(line, 10))
	{
		ex = ft_split(line, 10);
		i = 0;
		while (ex[i])
		{
			if (ft_count_c(ex[i], 36))
			{
				ex[i] = ft_get_env(ex[i]);
			}
			i++;
		}
	}
	else
		return (ft_get_env(line));
	i = 0;
	line = ft_strdup("");
	while (ex[i])
	{
		line = ft_strjoin(line, ex[i]);
		line = ft_strjoin(line, " ");
		i++;
	}
	return (line);
}

char	*ft_expend(char *line)
{
	char	**s;
	int		i;


	s = ft_split(line, ' ');
	i = 0;
	while (s[i])
	{
		//printf("her = %s\n", s[i]);
		if (ft_count_c(s[i], 36))
		{
			s[i] = ft_check_n(s[i]);
		}
		//printf("her2 = %s\n", s[i]);
		i++;
	}
	line = ft_strdup("");
	i = 0;
	while (s[i])
	{
		line = ft_strjoin(line, s[i]);
		//if (s[i + 1])
		line = ft_strjoin(line, " ");
		i++;
	}
	return (line);
}
