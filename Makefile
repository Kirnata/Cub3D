NAME = cub3D

MLX			= libmlx.dylib

MLX_H		= ./mlx/mlx.h

CUB			= cub/start_game.c \
			cub/my_mlx_pixel_put.c \
			cub/render.c \
			# ray_cast_srcs/hooks.c

GNL			= get_next_line.c\
			get_next_line_utils.c

PARSER		= check.c \
			error.c \
			parse.c \
			utils.c

SRCS		= $(addprefix src/, $(CUB))\
			$(addprefix src/parser/, $(PARSER))\
			$(addprefix src/get_next_line/, $(GNL))\
			src/main.c

OBJS		= $(SRCS:.c=.o)

OBJ_D		= $(SRCS:.c=.d)

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -O2 -MMD -I inc -I libft -I

MLX_FLAGS = -L mlx -l mlx -framework OpenGL -framework AppKit

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
			$(CC) $(СFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
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
