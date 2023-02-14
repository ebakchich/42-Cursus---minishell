/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_her.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:37:21 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/13 16:43:53 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    ft_ex_c(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == 34 || line[i] == 39)
            return (line[i]);
        i++;
    }
    return (-1);
}

char    **ft_ex_del(char **token, int l)
{
    char    **del;
    int i;
    int k;

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

void    ft_check_her(t_cmd *cmd, char **token)
{
    char    *her;
    char    **del;
    int count;
    int l;
    int i;
    int j;

    cmd->her = ft_strdup("");
    l = ft_count_str(token, "<<");
    if (l == 0)
        return ;
    i = 0;
    del = ft_ex_del(token, l);
    while (i < l)
    {
        count = ft_count_c(del[i], 34) + ft_count_c(del[i], 39);
        ft_remove_c(del[i], ft_ex_c(del[i]));
        j = 1;
        while (j)
        {
            her = readline("heredoc> ");
            if (ft_memcmp(her, del[i], ft_strlen(her)) == 0)
                j = 0;
            if (j != 0)
            {
                cmd->her = ft_strjoin(cmd->her, her);
                cmd->her = ft_strjoin(cmd->her, "\n");
            }
        }
            if (count == 0 && ft_count_c(cmd->her, 36))
            {
                // printf("1 = %s\n", cmd->her);
                cmd->her = ft_expend(cmd->her);
                //printf("2 = %s\n", cmd->her);
            }
        i++;
    }
    //cmd->her[ft_strlen(cmd->her) - 1] = '\0';
    printf("%s\n", cmd->her);
}
