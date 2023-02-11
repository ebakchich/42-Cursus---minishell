/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:37:59 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/11 08:07:16 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_alloc_db(t_cmd *cmd, char **token)
{
    int l;

    l = ft_count_str(token, "<");
    if (l != 0)
        cmd->infile = malloc(l * sizeof(int *));
    l = ft_count_str(token, ">");
    if (l != 0)
        cmd->outfile = malloc(l * sizeof(int *));
    l = ft_count_str(token, ">>");
    if (l != 0)
        cmd->apend = malloc(l * sizeof(int *));
}

// int ft_get_name(t_cmd *cmd, char *s, int k)
// {
//     if (k == 1)
//         cmd->outfile
//     return (0);
// }

void    ft_parse_cmd(t_cmd *cmd, char **token, char **env)
{
    int i;

    ft_check_her(cmd, token);
    //ft_alloc_db(cmd, token);
    // i = 0;
    // while (token[i])
    // {
    //     if (ft_memcmp(">>", token[i], 2) == 0)
    //         i = ft_get_name(cmd, token[i + 1], 1);
    // //     else if (ft_memcmp("<<", token[i], 2) == 0)
    // //         i = ;
    // //     else if (token[i][0] == '>')
    // //         i = ;
    // //     else if (token[i][0] == '<')
    // //         i = ;
    // //     else
    // //         i = ;
    // }

    // i = 0;
    // while (token[i])
    // {
    //     printf("%s\n", token[i]);
    //     i++;
    // }
    // printf("!!!!!!\n");
}
