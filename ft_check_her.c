/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_her.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:37:21 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/04 05:07:50 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_ex_c(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 34 || line[i] == 39)
			return (line[i]);
		i++;
	}
	return (-1);
}

char	**ft_ex_del(char **token, int l)
{
	char	**del;
	int		i;
	int		k;

	k = 0;
	i = 0;
	del = malloc((l + 1) * sizeof(char *));
	while (token[i])
	{
		if (ft_memcmp(token[i], "<<", 2) == 0)
		{
			del[k] = ft_strdup(token[i + 1]);
			k++;
		}
		i++;
	}
	del[k] = NULL;
	return (del);
}

void	ft_check_her2(t_cmd *cmd, char *del, int j, size_t len)
{
	char	*her;

	signal(SIGINT, signal_handler);
	while (j)
	{
		her = readline("> ");
		if (her == NULL)
			j = 0;
		else
		{
			len = ft_strlen(del);
			if (len < ft_strlen(her))
				len = ft_strlen(her);
			if (ft_memcmp(her, del, len) == 0
				|| (ft_strlen(del) == 0 && ft_strlen(her) == 0))
				j = 0;
			if (j != 0)
			{
				cmd->her = ft_strjoin(cmd->her, her);
				cmd->her = ft_strjoin(cmd->her, "\n");
			}
		}
		free(her);
	}
}

void	ft_check_her(t_cmd *cmd, char **token, int i)
{
	char	**del;
	int		count;
	int		l;

	cmd->her = ft_strdup("");
	l = ft_count_str(token, "<<");
	if (l == 0)
		return ;
	del = ft_ex_del(token, l);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
	while (i < l)
	{
		count = ft_count_c(del[i], 34) + ft_count_c(del[i], 39);
		del[i] = ft_remove_c2(del[i], ft_ex_c(del[i]));
		del[i] = ft_remove_c2(del[i], ' ');
		ft_check_her2(cmd, del[i], 1, 0);
		if (count == 0 && ft_count_c(cmd->her, 36))
			cmd->her = ft_before_expend(cmd->her, 0);
		i++;
	}
	ft_free(NULL, del);
}
