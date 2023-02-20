SRCS    = main.c ft_check_quote.c ft_getcmd.c ft_parse_cmd.c ft_common_functions.c ft_check_her.c ft_expend.c ft_free.c
NAME    = minishell
OBJS 	= ${SRCS:.c=.o}
LBFT	= libft/libft.a
CC		= cc -g
GFLAGS  = -Wall -Wextra -Werror -lreadline #-fsanitize=address 
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
