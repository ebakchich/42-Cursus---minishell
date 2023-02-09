/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:37:59 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/09 10:34:06 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_parse_cmd(t_cmd *cmd, int x, char **token, char **env)
{
    int i;

    i = 0;
    while (token[i])
    {
        if (ft_memcmp(">>", token[i], 2) == 0)
            i = ;
        else if (ft_memcmp("<<", token[i], 2) == 0)
            i = ;
        else if (token[i][0] == '>')
            i = ;
        else if (token[i][0] == '<')
            i = ;
        else
            i = ;
    }
} 
