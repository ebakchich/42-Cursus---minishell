/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:07:19 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/08 11:19:21 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdlib.h>

typedef struct t_cmd
{
    int     built;
    char    *cmd;
    char    **full_cmd;
    char    *path;
    int     infile;
	int     outfile;
    char    **envp;
}   t_cmd;

char    **ft_split(char *s, char c);
int     ft_check_quote(char **line);
int     ft_count_c(char *line, int c);
char	*ft_strchr(const char *s, int c);
char    *ft_strchr(const char *s, int c);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *s1);
int     ft_chrafter(char *line, int i, int c);
int     ft_chrafterr(char *line, int i);
size_t  ft_strlen(const char *s);
t_cmd    *ft_getcmd(char **full_cmd);

#endif
 