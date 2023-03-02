/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_expend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:53:25 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/02 17:06:18 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_expend_ex2(char *line)
{
    char    *new;
    char    *x;
    int     len;
    int     i;
    int     j;

    x = ft_itoa(g_ex.exit_status);
    if (ft_strlen(line) == 1)
        return (x);
    len = ft_strlen(x);
    new = malloc((len + ft_strlen(line)) * sizeof(char));
    i = 0;
    while (x[i])
    {
        new[i] = x[i];
        i++;
    }
    j = 1;
    while (line[j])
    {
        new[i] = line[j];
        j++;
        i++;
    }
    new[i] = '\0';
    return (new);
}

char    *ft_expend_ex(char *line)
{
    char    **ex;
    int     count;
    int     i;

    line = add_befor_c(line, '$');
    line = add_befor_c(line, ' ');
    ex = ft_split(line, -1);
    count = 0;
    i = 0;
    while (ex[i])
    {
        if (ex[i][0] == '$')
            count++;
        if (ex[i][0] == '?' && ex[i - 1][0] == '$' && count != 0 && count % 2 != 0)
        {
            count = 0;
            ex[i - 1][0] = -1; 
            ex[i] = ft_expend_ex2(ex[i]);
        }
        i++;
    }
    i = 0;
    line = ft_strdup("");
    while (ex[i])
    {
        if (ex[i][0] != -1)
            line = ft_strjoin(ex[i], line);
        i++;
    }
    return (line);
}

char    *ft_before_expend(char *t)
{
    char    **sp;
    int     i;
    int     count;
    int     count2;

    t = add_befor_c(t, 39);
    sp = ft_split(t, -1);
    count = 0;
    count2 = 0;
    i = 0;
    while (sp[i])
    {
        if (sp[i][0] == 39)
            count++;
        if (sp[i][0] == 34)
            count2++;
        if (((count != 0 || sp[i][0] != 39) && (count % 2 == 0) && ft_count_c(sp[i], '$')) || ((count % 2 != 0)))
        {
            count = 0;
            printf("her = %s\n", sp[i]);
            sp[i] = ft_expend(sp[i]);
        }
        i++;
    }
    t = ft_join_all(sp);
    return (t);
}
