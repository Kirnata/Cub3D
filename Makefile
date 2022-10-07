NAME = cub3D

MLX			= libmlx.dylib

MLX_H		= ./mlx/mlx.h

RAYCAST			= raycast/create_image.c \
			raycast/my_mlx_pixel_put.c \
			raycast/game.c \
			raycast/data_init.c \
			raycast/line_render.c \
			raycast/render_after_move.c \
			raycast/key_hooks.c \
			raycast/minimap.c \
			raycast/create_textures.c   \

GNL			= get_next_line.c\
			get_next_line_utils.c

PARSER		= check.c \
			error.c \
			parse.c \
			map.c \
			map2.c \
			textures.c \
			textures2.c \
			colours.c \
			check_probel_map.c \
			colours2.c

SRCS		= $(addprefix src/, $(RAYCAST))\
			$(addprefix src/parser/, $(PARSER))\
			$(addprefix src/get_next_line/, $(GNL))\
			src/main.c \
			src/cleaners.c \

OBJS		= $(SRCS:.c=.o)

OBJ_D		= $(SRCS:.c=.d)

CC			= gcc

#-Wall -Wextra -Werror
CFLAGS		= -Wall -Wextra -Werror -O3 -MMD -Iinc -Ilibft -Imlx -fsanitize=address -g -lasan

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT		= libft/libft.a

RM			= rm -rf

RED			= \x1b[31m
RESET		= \x1b[0m
BLUE		= \x1b[34m
GREEN		= \x1b[32m

$(NAME):	$(OBJS) $(MLX)
			@make bonus -C libft
			@echo "$(RED)Generating object files $(RESET)"
			@echo "$(BLUE)Compiling and linking binary file $(RESET)"
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
			@echo "$(GREEN)IT IS FINALLY GENERATED (to use it run $(RED)./$(NAME)$(GREEN)) $(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) mlx -c $< -o $(<:.c=.o)

$(MLX):		$(MLX_H)
			./build_mlx.sh

all:		$(NAME)

clean:
			@$(RM) $(OBJ_D) $(OBJS)
			make clean -C libft

fclean: clean
			@$(RM) $(NAME)
			make fclean -C libft

re: 		fclean all

.PHONY: 	all clean fclean re bonus

-include $(wildcard $(OBJ_D))
