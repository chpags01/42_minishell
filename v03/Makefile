NAME = minishell

SRCS		=	main.c \
			./util/ft_isalnum.c \
			./util/ft_itoa.c \
			./util/ft_split.c \
			./util/ft_strcmp.c \
			./util/ft_strjoin.c \
			./util/ft_strlen.c \
			./util/ft_strncmp.c \
			./util/ft_strlcpy.c \
			./util/ft_strdup.c \
			./util/ft_atoi.c \
			./util/ft_isspace.c \
			./util/ft_putstr_fd.c \
			./util/ft_system_calls.c \
			./util/ft_system_calls2.c \
			./util/is_exist_file.c \
			./util/exit_with_error.c \
			./util/signal.c \
			./parser/ft_split_argc.c \
			./parser/ft_strjoin_char.c \
			./parser/parse.c \
			./parser/argc_checker.c \
			./struct/cmd.c \
			./env/env.c

OBJS		= $(SRCS:%.c=%.o)

CC = gcc 
CFLAGS = 
# -Werror -Wall -Wextra

READLINE_LIB 	= -lreadline -L/opt/homebrew/opt/readline/lib
READLINE_INC	= -I/opt/homebrew/opt/readline/include
#READLINE_LIB 	= -lreadline -L${HOME}/.brew/opt/readline/lib
#READLINE_INC	= -I${HOME}/.brew/opt/readline/include

FT_DIR	= ./libft
FT 	= ft

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(READLINE_LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(READLINE_INC) -c $< -o $@

clean		:
		rm -f $(OBJS)

fclean		:	clean
		rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
