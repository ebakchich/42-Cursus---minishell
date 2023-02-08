/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:53:29 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/08 10:56:47 by ebakchic         ###   ########.fr       */
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

t_cmd    *ft_getcmd(char **full_cmd)
{
    t_cmd	*cmd;
    char    **token;
    int     i;

    cmd = malloc((ft_dblen(full_cmd) + 1) * sizeof(t_cmd));
    i = 0;
    while (full_cmd[i])
    {
        token = ft_split(full_cmd[i], ' ');
        ft_parse_cmd(cmd[i], token);
    }
    full_cmd[i] = NULL;
    return (cmd);
}
