# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 14:29:09 by ebakchic          #+#    #+#              #
#    Updated: 2023/03/02 18:03:03 by yoyahya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strncmp.c ft_toupper.c ft_bzero.c ft_isascii.c ft_memchr.c  ft_memset.c  ft_strlcpy.c ft_strrchr.c ft_isalnum.c ft_isdigit.c ft_memcpy.c  ft_strchr.c  ft_strcmp.c ft_strlen.c  ft_tolower.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c  ft_strmapi.c ft_putchar_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_itoa.c ft_striteri.c
NAME	= libft.a
OBJS    = ${SRCS:.c=.o}
CC      = cc
GFLAGS  = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(CC) $(GFLAGS) -c $(SRCS)
	@ar rcs $(NAME) ${OBJS}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
