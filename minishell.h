/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:07:19 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/13 10:00:01 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdlib.h>
#include <fcntl.h>

typedef struct t_cmd
{
	char	**cmd; //done
	int		*infile; //done
	int		*outfile; //done
	char	*her; //done
	int		*apend; //done
	char	**envp; //done
}   t_cmd;

char    **ft_split(char *s, char c);
char	*ft_strchr(const char *s, int c);
char    *ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
size_t  ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

int     ft_check_quote(char **line);
int     ft_chrafter(char *line, int i, int c);
int     ft_chrafterr(char *line, int i);
t_cmd   *ft_getcmd(char **full_cmd, char **env);
void    ft_parse_cmd(t_cmd *cmd, char **token, char **env);
void    ft_chng_c(char *line, char c);
void    ft_check_her(t_cmd *cmd, char **token);
char	*ft_expend(char *line);


int		ft_count_str(char **token, char *str);
int		ft_chrafterr(char *line, int j);
void	ft_chng_c(char *line, char c);
int		ft_count_c(char *line, int c);
void	ft_remove_c(char *line, int c);

#endif
 