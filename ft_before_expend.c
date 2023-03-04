/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_expend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:53:25 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/04 06:16:01 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expend_ex2(char *line, int i, int j, int len)
{
	char	*new;
	char	*x;

	x = ft_itoa(g_ex.exit_status);
	if (ft_strlen(line) == 1)
	{
		free(line);
		return (x);
	}
	len = ft_strlen(x);
	new = malloc((len + ft_strlen(line)) * sizeof(char));
	while (x[i])
	{
		new[i] = x[i];
		i++;
	}
	while (line[j])
	{
		new[i] = line[j];
		j++;
		i++;
	}
	new[i] = '\0';
	free(line);
	free(x);
	return (new);
}

int	ft_chr_q2(char **ex, int k, int i)
{
	while (k < i)
	{
		if (ex[k][0] == 34 || ex[k][0] == 39)
			return (k);
		k++;
	}
	return (-1);
}

int	ft_check_q(char **ex, int i)
{
	int		k;
	int		ch;
	int		count;

	count = 0;
	ch = ft_chr_q2(ex, 0, i);
	if (ch == -1)
		return (1);
	k = 0;
	while (k < i)
	{
		if (ex[k][0] == ex[ch][0])
			count++;
		k++;
		if ((count % 2) == 0 && count != 0)
		{
			count = 0;
			ch = ft_chr_q2(ex, k, i);
			if (ch == -1)
				return (1);
		}
	}
	if (count % 2 && ex[ch][0] == 39)
		return (0);
	return (1);
}

int	ft_count_dol(char **ex, int x)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < x)
	{
		printf("ex[i] = %s\n", ex[i]);
		if (ex[i][0] == '$')
			count++;
		else
			count = 0;
		i++;
	}
	if (count % 2 == 0)
		return (0);
	return (1);
}

char	*ft_expend_ex(char *line)
{
	char	**ex;
	int		count;
	int		i;

	line = add_befor_c(line, '$');
	line = add_befor_c(line, ' ');
	ex = ft_split(line, -1);
	count = 0;
	i = 0;
	while (ex[i])
	{
		if (ex[i][0] == '$')
			count++;
		if (ex[i][0] == '?' && ex[i - 1][0] == '$'
			&& ft_count_dol(ex, i) && ft_check_q(ex, i))
		{
			count = 0;
			ex[i - 1][0] = -1;
			ex[i] = ft_expend_ex2(ex[i], 0, 1, 0);
		}		
		i++;
	}
	free(line);
	line = ft_join_all2(ex);
	return (line);
}

char	*ft_before_expend(char *t, int x)
{
	char	**ex;
	int		i;

	t = ft_expend_ex(t);
	if (x == 0)
		return (ft_expend(t));
	t = ft_check_sp(t);
	ex = ft_split(t, -1);
	i = 0;
	while (ex[i])
	{
		if (ft_count_c(ex[i], '$') && ft_check_q(ex, i))
			ex[i] = ft_expend(ex[i]);
		i++;
	}
	free(t);
	t = ft_join_all(ex);
	ft_free(NULL, ex);
	return (t);
}
