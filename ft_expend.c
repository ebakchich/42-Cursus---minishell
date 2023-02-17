/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 06:18:50 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/16 17:53:50 by ebakchic         ###   ########.fr       */
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

char	*ft_check_sp(char *l)
{
	char	*new;
	int	x;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (1)
	{	
		while (l[j] && l[j] != '$')
		{
			j++;
			i++;
		}
		while (l[j] && ((l[j] > 96 && l[j] < 123) || (l[j] > 64 && l[j] < 90) || (l[j] > 47 && l[j] < 57) || (l[j] == '$')))
			j++;
		if (l[j] == '\0')
			break ;
	}
	i = (i * 2) + ft_strlen(l);
	new = malloc((i + 1) * sizeof(char));
	j = 0;
	x = 0;
	while (j < i)
	{
		if (l[j] && ((l[j] > 96 && l[j] < 123) || (l[j] > 64 && l[j] < 90) || (l[j] > 47 && l[j] < 57) || (l[j] == '$')))
		{	
			while (l[j] && ((l[j] > 96 && l[j] < 123) || (l[j] > 64 && l[j] < 90) || (l[j] > 47 && l[j] < 57) || (l[j] == '$')))
				new[x++] = l[j++];
		}
		else
		{
			new[x++] = -1;
			new[x++] = l[j++];
			new[x++] = -1;
		}
	}
	new[x] = '\0';
	return (new);
}

char	*ft_get_env(char *line)
{
	char	**ex;
	int	i;

	line = ft_check_sp(line);
	ex = ft_split(line, -1);
	i = 0;
	while (ex[i])
	{
		if (ft_count_c(ex[i], '$'))
			ex[i] = getenv(ex[i] + 1);
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
