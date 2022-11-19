# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 22:15:16 by chan-hpa          #+#    #+#              #
#    Updated: 2022/11/19 12:49:08 by chan-hpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS		=	main.c \
			./env/ft_env.c \
			./env/ft_export_no_arg_utils.c \
			./env/ft_getenv.c \
			./env/env_utils.c \
			./utiles/ft_isalnum.c \
			./utiles/ft_itoa.c \
			./utiles/ft_split.c \
			./utiles/ft_strcmp.c \
			./utiles/ft_strjoin.c \
			./utiles/ft_strlen.c \
			./utiles/ft_strncmp.c \
			./utiles/ft_strlcpy.c \
			./utiles/ft_strdup.c \
			./utiles/ft_atoi.c \
			./utiles/ft_isspace.c \
			./utiles/ft_putstr_fd.c \
			./utiles/ft_system_calls.c \
			./utiles/ft_system_calls2.c \
			./utiles/is_exist_file.c \
			./utiles/exit_with_error.c \
			./utiles/signal.c \
			./parser/ft_split_argc.c \
			./parser/ft_strjoin_char.c \
			./parser/parse_set_quotes.c \
			./parser/parse.c \
			./parser/replace.c \
			./struct/cmd.c \
			./parser/replace_util.c \
			./parser/argc_checker.c

OBJS		= $(SRCS:%.c=%.o)

CC = gcc $(DEBUG)
CFLAGS = -Werror -Wall -Wextra
# SAN = -fsanitize=address -g3
DEBUG = -g
#READLINE_LIB 	= -lreadline -L/opt/homebrew/opt/readline/lib
#READLINE_INC	= -I/opt/homebrew/opt/readline/include
READLINE_LIB 	= -lreadline -L${HOME}/.brew/opt/readline/lib
READLINE_INC	= -I${HOME}/.brew/opt/readline/include

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
