/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:07:19 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/28 14:54:10 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdlib.h>

typedef struct t_cmd
{
    char    *cmd;
    char    **full_cmd;
    char    *path;
    int     infile;
	int     outfile;
    char    **envp;
}   t_cmd;

char    **ft_split(char const *s, char c);

#endif