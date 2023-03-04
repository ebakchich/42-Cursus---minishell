/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:52:07 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/04 21:21:35 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_name(char *str)
{
	char	*tmp;

	if (!str || !*str)
		return (NULL);
	tmp = ft_strchr(str, '=');
	if (!tmp && ft_strlen(str) > 0)
		return (ft_strdup(str));
	if (*tmp == '=' && *(tmp - 1) == '+')
		return (ft_substr(str, 0, (tmp - 1) - str));
	return (ft_substr(str, 0, tmp - str));
}

char	*get_val(char *str, int flag)
{
	char	*tmp;

	tmp = ft_strchr(str, '=');
	if (tmp && flag == 0)
		return (ft_substr(tmp, 1, ft_strlen(tmp + 1)));
	if (tmp && flag == 1)
		return (ft_substr(tmp, 0, ft_strlen(tmp)));
	return (NULL);
}

int	findenv(t_var *data, char *var, int *i)
{
	char	*str;
	char	*str1;
	size_t	count;

	*i = 0;
	str = get_name(var);
	if (!str || !var)
		return (1);
	while (data->env[(*i)])
	{
		str1 = get_name(data->env[(*i)]);
		count = ft_strlen(str);
		if (count < ft_strlen(str1))
			count = ft_strlen(str1);
		if (str1 && ft_strncmp(str1, str, count) == 0)
		{
			free(str1);
			free(str);
			return (0);
		}
		(*i)++;
		free(str1);
	}
	free(str);
	return (1);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char		*str;
	size_t		tlen;
	size_t		i;
	size_t		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	tlen = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(tlen * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	**free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
