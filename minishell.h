/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:07:19 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/04 21:34:07 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/errno.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_var
{
	char	**env;
}t_var;

typedef struct s_gl_data
{
	int		exit_status;
	pid_t	id;
	int		in;
	int		out;
	t_var	*var;
}	t_gl_data;

t_gl_data	g_ex;

typedef struct t_cmd
{
	int		if_v;
	int		num_pip;
	char	**cmd;
	int		infile;
	int		outfile;
	char	*her;
	int		apend;
}	t_cmd;

char	**ft_split(char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_remove_db(char *l, int x);
char	*ft_strjoin(char *s1, char *s2);
char	*add_befor_c(char *line, int c);
char	*ft_check_sp(char *l);
char	*ft_expend(char *line);
char	*ft_before_expend(char *t, int i);
char	*ft_join_all(char **ex);
char	*get_env(char **env, char *line);
char	*ft_itoa(int n);
char	*ft_expend_ex(char *line, int i, int count);
char	*ft_remove_c2(char *line, int c);
char	*ft_join_all2(char **ex);
char	*ft_rm_tab(char *line);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_check_quote(char **line);
int		ft_chrafter(char *line, int i, int c);
int		ft_chrafterr(char *line, int i);
int		ft_ex_c(char *line);
int		ft_check_error_file(char *name, int j, t_cmd *cmd);
int		ft_count_str(char **token, char *str);
int		ft_chrafterr(char *line, int j);
int		ft_count_c(char *line, int c);
int		ft_atoi(const char *str);
int		ft_count_dol(char **ex, int x);

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	ft_parse_cmd(t_cmd *cmd, char **token, int count);
void	ft_chng_c(char *line, char c);
void	ft_check_her(t_cmd *cmd, char **token, int i);
void	ft_free(char *p, char **p2);
void	ft_free_cmd(t_cmd *cmd);
void	ft_chng_c(char *line, char c);
void	ft_remove_c(char *line, int c);	
void	rl_replace_line(const char *text, int clear_undo);
void	signal_handler(int signum);
void	signal_handler_her(int signum);
void	ft_get_fd(t_cmd *cmd, char **t, char *str, int j);
void	signal_handler_ch(int signum);
void	ft_putstr_fd(char *s, int fd);

t_cmd	*ft_getcmd(char **full_cmd);

size_t	ft_strlen(const char *s);

////////////// exec //////////

void	waitpro(int ncmd, int *status);
int		update(t_var **data, char *old);
int		sel_builtin(t_cmd *cmd, t_var *data, int flag);
char	*ft_strjoin1(char *s1, char *s2);
int		findenv(t_var *data, char *var, int *i);
int		is_valid(char *str);
char	**remenv(char **env, int pos, int len);
int		unset(t_var *data, char **cmd);
int		ft_pwd(void);
int		is_builtin(char *cmd);
int		valexp(char **env, char *var, int *flag);
int		repenv(t_var *data, char *var, int pos, int len);
int		appenv(t_var **data, char *var);
int		ft_export(t_var *var, char **cmd);
int		env(char **env);
int		countn(char *str);
int		echo(char **str);
int		check_old(char **env);
char	**free_matrix(char **str);
int		len_matrix(char **arr);
int		unset_err(char *str, int flag);
int		cd_err(char *str, int flag);
char	**dup_matrix(char **env);
int		export_err(char *str, int flag);
int		err_alloc(char *str);
int		ft_exec(t_var *var, t_cmd *cmd);
void	rid(t_cmd data);
int		builtin(t_cmd *cmd, t_var *var, int fork);
int		cd(char **cmd, t_var *data);
int		cd_1(t_var *data);
void	ft_exit(t_cmd *cmd);
char	*get_path(t_var *var, t_cmd *cmd);
int		exec_cmd(t_cmd *cmd, t_var *var);
int		sin_cmd(t_var *data, t_cmd *cmd);
void	rid(t_cmd data);
int		mult_cmd(t_cmd *cmd, t_var *var, int pip_in, int i);
int		printenv(char **env);
int		joinenv(t_var **var, char *cmd);
char	*get_name(char *str);
char	*get_val(char *str, int flag);
char	*delchar(char *cmd, char c);
int		updpwd(t_var *data);
char	*ft_strjoin_3(char *s1, char *s2);
int		check_acc(char *command, char **path);
int		joinenv3(t_var **var, char *vale, char *val, int pos);
int		joinenv2(t_var **var, char *val, int pos);
int		ft_export2(t_var *var, char *cmd, int flag);
void	herdoc(t_cmd data);
int		fill_ex(int *i, char **nenv, char *var);

#endif
