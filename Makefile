# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenaut- <ghenaut-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 14:03:47 by ghenaut-          #+#    #+#              #
#    Updated: 2023/03/06 20:46:23 by ghenaut-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all bonus clean fclean re

NAME		= cub3D
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3
HEADER		= cub3d.h

# B_NAME		= fdf_bonus

LIBFT	= libft.a
MLX		= mlx.a
IFT		= -Ilibft -Llibft -lft
IMLX	= -Imlx -Lmlx -lmlx -lXext -lX11 -lm

SRCS	= 	cub3d.c \
			init_data.c \
			exit.c \
			get_texture_path.c \

# B_SRCS	=   fdf_bonus.c \
# 			init_data_bonus.c \
# 			exit_bonus.c \
# 			draw_bonus.c \
# 			controls_bonus.c \
# 			views_bonus.c \
# 			isometric_bonus.c \
# 			utils_bonus.c

OBJSDIR	= ./obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})
# B_OBJS	= $(addprefix ${OBJSDIR}/, ${B_SRCS:%.c=%.o})

all: ${NAME}
	@make clean

# bonus: ${NAME}_bonus
# 	@make clean

${NAME}: ${OBJSDIR} ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${IFT} ${IMLX} -o $@

# ${NAME}_bonus: ${OBJSDIR} ${B_OBJS}
# 	@${CC} ${CFLAGS} ${B_OBJS} ${IFT} ${IMLX} -o $@

${OBJSDIR}:
	@mkdir -p $@

# ${OBJS}: | ${LIBFT} ${MLX}
# ${B_OBJS}: | ${LIBFT} ${MLX}

${OBJSDIR}/%.o: src/%.c includes/cub3d.h Makefile
	@${CC} ${CFLAGS} -c $< -o $@

# ${OBJSDIR}/%.o: bonus/%.c includes/fdf_bonus.h Makefile
# 	@${CC} ${CFLAGS} -c $< -o $@

${LIBFT}: | libft
	@${MAKE} -C libft/

${MLX}: | mlx
	@${MAKE} -C mlx/

clean:
	@rm -rf ${OBJSDIR}

fclean: clean
	@rm -rf ${NAME} ${NAME}_bonus
	@rm -rf vgcore*

re: fclean all
