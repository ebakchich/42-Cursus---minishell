/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 06:18:50 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/14 13:39:11 by ebakchic         ###   ########.fr       */
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
		line = ft_strjoin(line, ex[i]);
		i++;
	}
	return (line);
}

char	*add_befor_c(char *line, int c)
{
	char	*new;
	int	i;
	int	j;

	new = malloc((ft_strlen(line) + (ft_count_c(line, c) * 2) + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == c)
		{
			new[j++] = -1;
			new[j++] = line[i++];
			new[j++] = -1;
		}
		else
			new[j++] = line[i++];
	}
	new[j] = '\0';
	return (new);
}

char	*ft_get_env(char *line)
{
	char	**ex;
	int	i;

	ex = ft_split(line, 36);
	i = 0;
	while (ex[i])
	{
		ex[i] = getenv(ex[i]);
		i++;
	}
	line = ft_join_all(ex);
	return (line);
}

char	*ft_check_n(char *line)
{
	char	**ex;
	int	i;
	
	line = add_befor_c(line, 10);
	ex = ft_split(line, -1);
	i = 0;
	while (ex[i])
	{
		if (ft_count_c(ex[i], 36))
			ex[i] = ft_get_env(ex[i]);
		i++;
	}
	line = ft_join_all(ex);	
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
	}
	else if (ft_count_c(line, 10))
		line = ft_check_n(line);
	else
		line = ft_get_env(line);
	return (line);
}
