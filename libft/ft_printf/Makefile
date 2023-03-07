# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 19:39:47 by ghenaut-          #+#    #+#              #
#    Updated: 2022/07/01 16:20:30 by ghenaut-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all clean fclean re bonus

NAME	= libftprintf.a

CC		= clang
CFLAGS	= -Wall -Werror -Wextra
INC		= -I ./includes -I ..

LIB		= ../libft.a
SRCS = ./src/ft_printf_bonus.c \
		./src/add_char_bonus.c \
		./src/add_str_bonus.c \
		./src/ft_vprintf_bonus.c \
		./src/generate_rtn_str_bonus.c \
		./src/handle_conversions_bonus.c \
		./src/parse_arg_bonus.c \
		./src/utils.c \
		./src/add_int.c \
		./src/add_uint.c \
		./src/add_hex.c \
		./src/add_pointer.c \
		./src/add_percent.c \
		./src/handle_precision.c \

OBJS	= ${SRCS:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJS}
	@ar -rcs $@ $^

${OBJS}: | ${LIB}

.c.o:
	@${CC} ${CFLAGS} ${INC} -c $< -o ${<:%.c=%.o}

${LIB}:
	@${MAKE} -C libft/

clean:
	@rm -rf ./src/*.o

fclean: clean
	@rm -rf ${NAME}

re: fclean all