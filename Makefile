# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 02:43:28 by ebakchic          #+#    #+#              #
#    Updated: 2023/03/04 21:36:02 by ebakchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS    = main.c ft_check_quote.c ft_getcmd.c ft_parse_cmd.c ft_common_functions.c ft_check_her.c ft_expend.c ft_expend2.c ft_free.c ft_check_error_file.c ft_signals.c ft_before_expend.c \
	exec/cd.c exec/echo.c exec/env.c exec/exec.c exec/exit.c exec/export.c exec/get_path.c exec/is_builtin.c exec/exec_cmd.c exec/pwd.c exec/unset.c exec/utils.c \
	exec/cd_utils.c exec/unset_utils.c exec/export_utils.c exec/builtin.c exec/utils2.c exec/export2.c
NAME    = minishell
LBFT	= libft/libft.a
CC		= cc -g
CFLAGS  = -Wall -Wextra -Werror
CRL		= -lreadline -L /Users/ebakchic/homebrew/Cellar/readline/8.2.1/lib -I /Users/ebakchic/homebrew/Cellar/readline/8.2.1/include #-fsanitize=address
MAKEC	= make clean
MAKEF	= make fclean
MAKER	= make re
OBJS 	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $(CRL) ${LBFT} ${OBJS} -o ${NAME}
	@stty -echoctl

clean:
	@$(MAKEC) -C libft
	@${RM} ${OBJS}

fclean: clean
	@$(MAKEF) -C libft
	@${RM} ${NAME}

re: fclean all
	@$(MAKER) -C libft

.PHONY: all clean fclean re
