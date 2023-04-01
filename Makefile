# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 14:03:47 by ghenaut-          #+#    #+#              #
#    Updated: 2023/04/01 03:34:54 by harndt           ###   ########.fr        #
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
SRCS		:=	./src/bresenham.c					\
				./src/cub3d.c						\
				./src/debug.c						\
				./src/draw.c						\
				./src/draw_walls.c					\
				./src/exit.c						\
				./src/free.c						\
				./src/get_map.c						\
				./src/get_texture_path.c			\
				./src/get_textures.c				\
				./src/hooks_checker_horizontal.c	\
				./src/hooks_checker_vertical.c		\
				./src/hooks_utils.c					\
				./src/hooks.c						\
				./src/image.c						\
				./src/init_data.c					\
				./src/init_found.c					\
				./src/init_mlx.c					\
				./src/init_ray.c					\
				./src/raycaster.c					\
				./src/utils.c						\
				./src/validate_map.c

OBJS		:=	$(SRCS:.c=.o)

# ==============================================================================
# VALGRIND VARIABLES
# ==============================================================================

ARGV		:=	./test_maps/testmap.cub
# ARGV		:=	./tests/maps/valid/00_valid_texture_parameters.cub
# ARGV		:=	./tests/maps/valid/01_texture_ids_separated_by_many_spaces.cub
# ARGV		:=	./tests/maps/valid/06_valid_floor_colour_parameters.cub
# ARGV		:=	./tests/maps/valid/07_floor_colour_elements_separated_by_many_spaces.cub
# ARGV		:=	./tests/maps/valid/12_valid_ceiling_colour_parameters.cub
# ARGV		:=	./tests/maps/valid/13_ceiling_colour_elements_separated_by_many_spaces.cub
# ARGV		:=	./tests/maps/valid/30_scrambled_parameters_order.cub
# ARGV		:=	./tests/maps/valid/31_many_line_breaks_between_parameters.cub
# ARGV		:=	./tests/maps/valid/44_valid_square_map.cub
# ARGV		:=	./tests/maps/valid/46_valid_T_map.cub
# ARGV		:=	./tests/maps/valid/47_valid_irregular_map_surrounded_by_ones.cub
# ARGV		:=	./tests/maps/valid/51_starting_position_within_bumpy_map.cub
# ARGV		:=	./tests/maps/valid/52_starting_position_within_map_with_hole.cub

# ARGV		:=	./tests/maps/invalid/02_invalid_NO_texture_parameter.cub
# ARGV		:=	./tests/maps/invalid/03_invalid_SO_texture_parameter.cub
# ARGV		:=	./tests/maps/invalid/04_invalid_EA_texture_parameter.cub
# ARGV		:=	./tests/maps/invalid/05_invalid_WE_texture_parameter.cub
# ARGV		:=	./tests/maps/invalid/08_floor_colour_elements_with_trailing_commas.cub
# ARGV		:=	./tests/maps/invalid/09_floor_colour_elements_value_above_range.cub
# ARGV		:=	./tests/maps/invalid/10_floor_colour_elements_value_bellow_range.cub
# ARGV		:=	./tests/maps/invalid/11_floor_colour_elements_value_alfanumeric.cub
# ARGV		:=	./tests/maps/invalid/14_ceiling_colour_elements_with_trailing_commas.cub
# ARGV		:=	./tests/maps/invalid/15_ceiling_colour_elements_value_above_range.cub
# ARGV		:=	./tests/maps/invalid/16_ceiling_colour_elements_value_bellow_range.cub
# ARGV		:=	./tests/maps/invalid/17_ceiling_colour_elements_value_alfanumeric.cub
# ARGV		:=	./tests/maps/invalid/18_missing_NO_texture.cub
# ARGV		:=	./tests/maps/invalid/19_misplaced_NO_texture.cub
# ARGV		:=	./tests/maps/invalid/20_missing_SO_texture.cub
# ARGV		:=	./tests/maps/invalid/21_misplaced_SO_texture.cub
# ARGV		:=	./tests/maps/invalid/22_missing_EA_texture.cub
# ARGV		:=	./tests/maps/invalid/23_misplaced_EA_texture.cub
# ARGV		:=	./tests/maps/invalid/24_missing_WE_texture.cub
# ARGV		:=	./tests/maps/invalid/25_misplaced_WE_texture.cub
# ARGV		:=	./tests/maps/invalid/26_missing_F_colour.cub
# ARGV		:=	./tests/maps/invalid/27_misplaced_F_colour.cub
# ARGV		:=	./tests/maps/invalid/28_missing_C_colour.cub
# ARGV		:=	./tests/maps/invalid/29_misplaced_C_colour.cub
# ARGV		:=	./tests/maps/invalid/32_too_many_floor_colour_elements.cub
# ARGV		:=	./tests/maps/invalid/33_too_few_floor_colour_elements.cub
# ARGV		:=	./tests/maps/invalid/34_empty_floor_colour_element.cub
# ARGV		:=	./tests/maps/invalid/35_all_empty_floor_colour_elements.cub
# ARGV		:=	./tests/maps/invalid/36_too_many_ceiling_colour_elements.cub
# ARGV		:=	./tests/maps/invalid/37_too_few_ceiling_colour_elements.cub
# ARGV		:=	./tests/maps/invalid/38_empty_ceiling_colour_element.cub
# ARGV		:=	./tests/maps/invalid/39_all_empty_ceiling_colour_elements.cub
# ARGV		:=	./tests/maps/invalid/40_duplicate_NO_parameter.cub
# ARGV		:=	./tests/maps/invalid/41_duplicate_SO_parameter.cub
# ARGV		:=	./tests/maps/invalid/42_duplicate_EA_parameter.cub
# ARGV		:=	./tests/maps/invalid/43_duplicate_WE_parameter.cub
# ARGV		:=	./tests/maps/invalid/45_invalid_square_map.cub
# ARGV		:=	./tests/maps/invalid/48_invalid_map_with_invalid_character.cub
# ARGV		:=	./tests/maps/invalid/49_invalid_map_with_no_starting_position_character.cub
# ARGV		:=	./tests/maps/invalid/50_invalid_map_with_two_starting_position_characters.cub
# ARGV		:=	./tests/maps/invalid/53_starting_position_outside_bumpy_map.cub
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
			clear
			valgrind $(VGFLAGS) ./$(NAME) $(ARGV)

.PHONY:		all clean fclean re vg
