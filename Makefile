# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 14:03:47 by ghenaut-          #+#    #+#              #
#    Updated: 2023/03/10 21:27:13 by harndt           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================================================================
# VARIABLES
# ==============================================================================

NAME		:=	cub3D
CC			:=	cc
LINKS		:=	-lmlx -lm -Llibft -lXext -lX11
CFLAGS		:=	-O3 -g3 -Wall -Werror -Wextra
HEADERS		:=	includes
LIBFT		:=	./libft/libft.a
SRCS		:=	./src/cub3d.c	./src/exit.c	./src/get_map.c	\
				./src/get_texture_path.c		./src/init_data.c \
				./src/debug.c	./src/init_mlx.c	./src/hooks.c \
				./src/validate_map.c

OBJS		:=	$(SRCS:.c=.o)

# ==============================================================================
# VALGRIND VARIABLES
# ==============================================================================

ARGV		:=	./test_maps/map.cub
VGFLAGS		:=	--leak-check=full --show-leak-kinds=all

# ==============================================================================
# COLORS
# ==============================================================================

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHT			:=	\033[1;37m
EOC			:=	\033[1;0m

# ==============================================================================
# RECIPES	
# ==============================================================================

all:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
			@echo "$(WHT)Compiling CUB3D...$(EOC)"
			@$(CC) $(OBJS) $(LINKS) $(LIBFT) -o $@
			@echo "$(GREEN)CUB3D build completed.$(EOC)"

$(LIBFT):
			@echo "$(WHT)Compiling libft...$(EOC)"
			@make -C libft
			@echo "$(GREEN)Libft done.$(EOC)"

clean:
			@echo "$(WHT)Removing .o files...$(EOC)"
			@rm -f $(OBJS)
			@make -C libft clean
			@echo "$(GREEN)Clean done.$(EOC)"

fclean:		clean
			@echo "$(WHT)Removing object- and binary -files...$(EOC)"
			@rm -f $(NAME)
			@make -C libft fclean
			@echo "$(GREEN)Fclean done.$(EOC)"

re:			fclean all

run:		all
			clear
			./$(NAME) $(ARGV)

vg:			all
			valgrind $(VGFLAGS) ./$(NAME) $(ARGV)

.PHONY:		all clean fclean re vg
