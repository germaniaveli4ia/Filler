NAME		:= wmarya.filler

MAKE 		:= make
# directories
INC_DIR		:= ./includes

LIBFT		:= ./libft
LIBFT_INC	:= $(LIBFT)/includes
LIBFT_LNK 	:= -L $(LIBFT) -l ft

LIBS_INC	:= -I $(LIBFT_INC)
LIBS_LNK	:= $(LIBFT_LNK)

V_DIR		:= ./visual/

SRC_DIR		:= ./src
SRC_FILES	:=  main.c \
				init.c \
				parse.c \
				fill_structures.c \
				fight.c \
				free.c \

SRC			:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			:= $(SRC:.c=.o)

# compiler and flags
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror

# COLORS

GREEN = \033[0;32m

.PHONY: all clean fclean re

%.o:%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(LIBS_INC) -c $< -o $@

$(NAME): libs $(OBJ)
	@$(CC) $(OBJ) $(LIBS_LNK) -I $(INC_DIR) -o $(NAME) $(CFLAGS)
	@$(MAKE) -C $(V_DIR)
	@echo "$(GREEN)$(NAME) was created"

all: $(NAME)

clean:
	@$(MAKE) -C $(LIBFT) clean --no-print-directory
	@$(MAKE) -C $(V_DIR) clean --no-print-directory
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(V_DIR) fclean --no-print-directory
	@$(MAKE) -C $(LIBFT) fclean --no-print-directory

re: fclean all

libs:
	@$(MAKE) -C $(LIBFT) --no-print-directory

relib:
	@$(MAKE) -C $(LIBFT) re --no-print-directory
	@$(MAKE) re --no-print-directory
