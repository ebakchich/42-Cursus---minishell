/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:15:37 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/21 17:59:25 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_check_error_file(char *name, int j, int *if_v)
{
    int v;

    v = -1;
    if (j == 1)
    {
        if (access(name, F_OK) == -1)
        {
            if_v = &v;
		    write(2, "Error: No such file or directory\n", 33);
            return (1);
        }
	    if (access(name, R_OK) == -1)
        {
            if_v = &v;
		    write(2, "Error: permission denied\n", 25);
            return (1);
        }
    }
    else
    {
        if (access(name, F_OK) != -1)
        {
            if (access(name, W_OK) == -1)
            {
                if_v = &v;
		        write(2, "Error: permission denied\n", 25);
                return (1);
            }
        }
    }
    return (1);
}