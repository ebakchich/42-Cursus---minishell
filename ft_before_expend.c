/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_expend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:53:25 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/03 22:43:45 by ebakchic         ###   ########.fr       */
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

int ft_chr_q2(char **ex, int k, int i)
{
    while (k < i)
    {
        if (ex[k][0] == 34 || ex[k][0] == 39)
            return (k);
        k++;
    }
    return (-1);
}

int ft_check_q(char **ex, int i)
{
    int k;
    int ch;
    int count;

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
        if (ex[i][0] == '?' && ex[i - 1][0] == '$' && count != 0 && count % 2 != 0 && ft_check_q(ex, i))
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
            line = ft_strjoin(line, ex[i]);
        i++;
    }
    return (line);
}

char    *ft_before_expend(char *t)
{
    char    **ex;
    int     i;

    t = ft_expend_ex(t);
    t = ft_check_sp(t);
    ex= ft_split(t, -1);
    i = 0;
    while (ex[i])
    {
        if (ft_count_c(ex[i], '$') && ft_check_q(ex, i))
            ex[i] = ft_expend(ex[i]);
        i++;
    }
    t = ft_join_all(ex);
    return (t);
}
