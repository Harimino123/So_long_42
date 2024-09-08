SHELL := /bin/bash

NAME = so_long

FLAGS = -lXext -lX11 -lm

FLAGS_C = -Wall -Werror -Wextra -g -O1

RM = rm -rf

SRCS = main.c \
	GNL/get_next_line_utils.c \
	GNL/get_next_line.c \
	src/ft_error_check.c \
	src/load_map.c \
	src/ft_parsing_map.c \
	src/content_set.c \
	src/utils.c \
	src/ft_key_set.c

LIBFT_PATH = Libft

LIBFT = $(LIBFT_PATH)/libft.a

PRINTF_PATH = Printf

PRINTF = $(PRINTF_PATH)/libftprintf.a

MLX_PATH = mlx

MLX = $(MLX_PATH)/libmlx.a

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	cc $(OBJS) $(LIBFT) $(PRINTF) $(FLAGS_C) $(MLX) $(FLAGS) -o $(NAME)

all: $(NAME)

$(MLX) :
		@make -C $(MLX_PATH)

$(PRINTF) :
		@make -C $(PRINTF_PATH)

$(LIBFT) :
		@make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJS)
	@make clean -C mlx
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(PRINTF_PATH)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(PRINTF_PATH)

re: fclean all
