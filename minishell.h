/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:07:19 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/21 17:59:33 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct t_var
{
	int		status;
	char	**env;
}	t_var;

typedef struct t_cmd
{
	int		if_v;
	int		num_pip;
	char	**cmd;
	int		infile;
	int		outfile;
	char	*her;
	int		apend;
}   t_cmd;

char    **ft_split(char *s, char c);
char	*ft_strchr(const char *s, int c);
char    *ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
size_t  ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);

int     ft_check_quote(char **line);
int     ft_chrafter(char *line, int i, int c);
int     ft_chrafterr(char *line, int i);
t_cmd   *ft_getcmd(char **full_cmd, char **env);
void    ft_parse_cmd(t_cmd *cmd, char **token, char **env);
void    ft_chng_c(char *line, char c);
void    ft_check_her(t_cmd *cmd, char **token);
char	*ft_expend(char *line);

int    ft_ex_c(char *line);
char	*ft_remove_db(char *l);

void	ft_free(char *p, char **p2);
void	ft_free_cmd(t_cmd *cmd);

int ft_check_error_file(char *name, int j, int *if_v);

int		ft_count_str(char **token, char *str);
int		ft_chrafterr(char *line, int j);
void	ft_chng_c(char *line, char c);
int		ft_count_c(char *line, int c);
void	ft_remove_c(char *line, int c);

#endif
 