/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:53:29 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/09 03:53:23 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_dblen(char **full_cmd)
{
    int i;

    i = 0;
    while (full_cmd[i])
        i++;
    return (i);
}

void    ft_init_cmd(t_cmd *cmd, int x)
{
    int i;

    i = 0;
    while (i < x)
    {
        cmd[i].cmd = NULL;
        cmd[i].full_cmd = NULL;
        cmd[i].path = NULL;
        cmd[i].infile = NULL;
        cmd[i].outfile = NULL;
        cmd[i].del_her = NULL;
        cmd[i].apend = NULL;
        cmd[i].envp = NULL;
        i++;
    }
}   

t_cmd    *ft_getcmd(char **full_cmd, char **env)
{
    t_cmd	*cmd;
    char    **token;
    int     i;

    cmd = malloc(ft_dblen(full_cmd) * sizeof(t_cmd));
    ft_init_cmd(cmd, ft_dblen(full_cmd));
    i = 0;
    while (full_cmd[i])
    {
        token = ft_split(full_cmd[i], ' ');
        ft_parse_cmd(cmd, i, token, env);
        free(token);
    }
    full_cmd[i] = NULL;
    return (cmd);
}
