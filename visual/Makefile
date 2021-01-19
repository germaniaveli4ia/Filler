NAME		:= visual

MAKE 		:= make
# directories
INC_DIR		:= ./includes

MLX			:= ./minilibx_macos
MLX_INC		:= $(MLX)/includes
MLX_LNK 	:= -L $(MLX) -l mlx

LIBFT		:= ../libft
LIBFT_INC	:= $(LIBFT)/includes
LIBFT_LNK 	:= -L $(LIBFT) -l ft

LIBS_INC	:= -I $(LIBFT_INC) -I $(MLX_INC)
LIBS_LNK	:= $(MLX_LNK) $(LIBFT_LNK)

SRC_DIR		:= ./src
SRC_FILES	:=  main.c \
				init.c \
				parse.c \
				free.c \
				draw.c \
				drawsomemore.c \
				utils.c

SRC			:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			:= $(SRC:.c=.o)

# compiler and flags
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror

.PHONY: all clean fclean re

%.o:%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(LIBS_INC) -c $< -o $@

$(NAME): libs $(OBJ)
	@$(CC) $(OBJ) $(LIBS_LNK) -I $(INC_DIR) -o $(NAME) $(CFLAGS) \
		-framework OpenGL -framework AppKit

all: $(NAME)

clean:
	@$(MAKE) -C $(LIBFT) clean --no-print-directory
	@$(MAKE) -C $(MLX) clean --no-print-directory
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT) fclean --no-print-directory

re: fclean all

libs:
	@$(MAKE) -C $(LIBFT) --no-print-directory
	@$(MAKE) -C $(MLX) --no-print-directory

relib:
	@$(MAKE) -C $(LIBFT) re --no-print-directory
	@$(MAKE) -C $(MLX) re --no-print-directory
	@$(MAKE) re --no-print-directory
