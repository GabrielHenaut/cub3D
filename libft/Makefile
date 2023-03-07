# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 14:54:52 by ghenaut-          #+#    #+#              #
#    Updated: 2022/07/12 00:22:15 by ghenaut-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: .c.o libft.a all clean fclean re

SRCS	= 	ft_memset.c \
			ft_strlen.c \
			ft_substr.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memjoin.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_strtoupper.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_itox.c \
			ft_uitoa.c \
			ft_uitoa.c \
			ft_uitox.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strrchr.c \
			get_next_line.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstfind.c \
			ft_sort.c

PRINTF_SRCS = ./src/ft_printf_bonus.c \
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
			

OBJS	= $(SRCS:.c=.o)
NAME	= libft.a


all: ${NAME}
# @make clean

${NAME}: ${OBJS}
	@ar -rcs $@ $^
	@make -C ft_printf/
	@ar -rs $@ ft_printf/src/*.o

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@make fclean -C ft_printf
	@rm -f *.o

fclean: clean
	@rm -f *.a

re: fclean all
