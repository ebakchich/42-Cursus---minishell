/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:42:55 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/04 21:00:42 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_join_all2(char **ex)
{
	char	*line;
	char	*tmp;
	int		i;

	tmp = ft_strdup("a");
	tmp[0] = -1;
	i = 0;
	line = ft_strdup("");
	while (ex[i])
	{
		line = ft_strjoin(line, ex[i]);
		if (i != 0 && ex[i - 1][0] == -1)
			line = ft_strjoin(line, tmp);
		i++;
	}
	free(tmp);
	ft_free(NULL, ex);
	return (line);
}

char	*add_befor_c(char *line, int c)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(line);
	new = malloc((len + (ft_count_c(line, c) * 2) + 1) * sizeof(char));
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
	free(line);
	new[j] = '\0';
	return (new);
}

void	ft_check_sp2(char *l, char *new, int i)
{
	int	j;
	int	x;

	j = 0;
	x = 0;
	while (j < i && l[j])
	{
		if ((l[j] > 96 && l[j] < 123) || (l[j] > 64 && l[j] < 90)
			|| (l[j] > 47 && l[j] < 57) || (l[j] == '$'))
			new[x] = l[j];
		else
		{
			new[x++] = -1;
			new[x++] = l[j];
			new[x] = -1;
		}
		x++;
		j++;
	}
	new[x] = '\0';
}

char	*ft_check_sp(char *l)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (1)
	{	
		while (l[j] && l[j] != '$')
		{
			j++;
			i++;
		}
		while (l[j] && ((l[j] > 96 && l[j] < 123) || (l[j] > 64 && l[j] < 90)
				|| (l[j] > 47 && l[j] < 57) || (l[j] == '$')) && l[j] != '?')
			j++;
		if (l[j] == '\0')
			break ;
	}
	i = (i * 2) + ft_strlen(l);
	new = malloc((i + 1) * sizeof(char));
	ft_check_sp2(l, new, i);
	free(l);
	return (new);
}
