/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:06:34 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/03 18:29:35 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_red_chr(char *l, int x)
{
	int		i;
	char	*c;

	c = "\n";
	i = 0;
	while (l[i] == ' ')
		i++;
	if (x == 0)
	{
		if (l[i] == '|')
		{
			printf("parse error near '%c'\n", l[i]);
			g_ex.exit_status = 258;
			return (-1);
		}
	}
	else
	{
		if (l[i] == '<' || l[i] == '>' || l[i] == '|' || l[i] == '\0')
		{
			printf("parse error near '%c'\n", l[i]);
			g_ex.exit_status = 258;
			return (-1);
		}
	}
	return (0);
}

int	ft_check_error(char *line, char *l, int x)
{
	int		i;

	i = 0;
	if (l[0] == '|' || l[ft_strlen(l) - 1] == '|')
	{
		printf("parse error near '%c'\n", line[i]);
		g_ex.exit_status = 258;
		return (-1);
	}
	while (line[i])
	{
		if (ft_chrafterr(l, x) && line[i] == '<' && line[i + 1] == '<')
			return (ft_red_chr(&line[i + 2], 1));
		else if (ft_chrafterr(l, x) && line[i] == '>' && line[i + 1] == '>')
			return (ft_red_chr(&line[i + 2], 1));
		else if (ft_chrafterr(l, x) && line[i] == '>')
			return (ft_red_chr(&line[i + 1], 1));
		else if (ft_chrafterr(l, x) && line[i] == '<')
			return (ft_red_chr(&line[i + 1], 1));
		if (ft_chrafterr(l, x) && line[i] == '|')
			return (ft_red_chr(&line[i + 1], 0));
		i++;
	}
	return (0);
}

void	ft_parse(char *line, t_var *var)
{
	t_cmd	*cmd;
	char	**full_cmd;
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("<>|", line[i]))
			if (ft_check_error(line + i, line, i))
				return ;
		i++;
	}
	ft_chng_c(line, '|');
	full_cmd = ft_split(line, -1);
	if (full_cmd == NULL)
		return ;
	if (ft_check_quote(full_cmd))
	{
		ft_free(NULL, full_cmd);
		return ;
	}
	cmd = ft_getcmd(full_cmd, var->env);
	ft_exec(var, cmd);
	ft_free_cmd(cmd);
	ft_free(NULL, full_cmd);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_var	*var;

	(void)av;
	(void)ac;
	var = malloc(sizeof(t_var));
	var->env = dup_matrix(env);
	if (!var->env)
	{
		perror("minishell");
		return (1);
	}
	g_ex.var = var;
	g_ex.exit_status = 0;
	g_ex.out = dup(1);
	g_ex.in = dup(0);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		signal(SIGINT, signal_handler);
		line = readline("\033[32;1m\U000025B6\033[0m \033[32;1mminishell $\033[0m ");
		if (line == NULL)
			exit (g_ex.exit_status);
		if (line[0] && line != NULL)
			add_history(line);
		if (line[0] != '\0')
			ft_parse(line, var);
		free(line);
	}
	return (0);
}
