# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 02:43:28 by ebakchic          #+#    #+#              #
#    Updated: 2023/02/28 07:44:39 by ebakchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.c ft_check_quote.c ft_getcmd.c ft_parse_cmd.c ft_common_functions.c ft_check_her.c ft_expend.c ft_expend2.c ft_free.c ft_check_error_file.c ft_signals.c ft_execution.c 
NAME    = minishell
OBJS 	= ${SRCS:.c=.o}
LBFT	= libft/libft.a
CC		= cc -g
GFLAGS  = -Wall -Wextra -Werror -lreadline -L /Users/ebakchic/homebrew/Cellar/readline/8.2.1/lib -I /Users/ebakchic/homebrew/Cellar/readline/8.2.1/include #-fsanitize=address 
MAKEC	= make clean
MAKEF	= make fclean
MAKER	= make re

all: $(NAME)

$(NAME): ${OBJS}
	@$(MAKE) -C libft
	@$(CC) $(GFLAGS) -o ${NAME} ${LBFT} ${OBJS}
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
