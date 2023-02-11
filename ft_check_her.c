/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_her.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:37:21 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/11 08:06:09 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
    char    *join;
    char    **del;
    char    *sp;
    int l;
    int i;
    int j;

    i = 0;
    join = ft_strdup("");
    sp = ft_strdup("|");
    sp[0] = 10;
    l = ft_count_str(token, "<<");
    if (l == 0)
        return ;
    del = ft_ex_del(token, l);
    while (i < l)
    {
        j = 1;
        while (j)
        {
            her = readline("heredoc> ");
            if (ft_memcmp(her, del[i], ft_strlen(her)) == 0)
                j = 0;
            if (j != 0)
            {
                join = ft_strjoin(join, her);
                join = ft_strjoin(join, sp);
            }
        }
        i++;
    }
    join[ft_strlen(join) - 1] = '\0';
    cmd->her = join;
}
