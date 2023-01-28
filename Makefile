# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 01:46:07 by ebakchic          #+#    #+#              #
#    Updated: 2023/01/28 08:38:32 by ebakchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.c
NAME    = minishell
OBJS 	= ${SRCS:.c=.o}
LBFT	= libft/libft.a
CC		= cc
GFLAGS  = -Wall -Wextra -Werror -lreadline
MAKEC	= make clean
MAKEF	= make fclean
MAKER	= make re

all: $(NAME)

$(NAME): ${OBJS}
	@$(MAKE) -C libft
	@$(CC) $(GFLAGS) -o ${NAME} ${LBFT} ${OBJS}

clean:
	@$(MAKEC) -C libft
	@${RM} ${OBJS}

fclean: clean
	@$(MAKEF) -C libft
	@${RM} ${NAME}

re: fclean all
	@$(MAKER) -C libft

.PHONY: all clean fclean re
