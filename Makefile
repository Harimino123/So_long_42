SHELL := /bin/bash

NAME = so_long

FLAGS = -lXext -lX11 -lm

FLAGS_C = -Wall -Werror -Wextra

RM = rm -rf

SRCS = main.c \
	GNL/get_next_line_utils.c \
	GNL/get_next_line.c \
	ft_error_check.c \
	load_map.c \
	ft_parsing_map.c \
	content_set.c \
	utils.c

LIBFT_PATH = Libft

LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = mlx

MLX = $(MLX_PATH)/libmlx.a

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	cc $(OBJS) $(LIBFT) $(FLAGS_C) $(MLX) $(FLAGS) -o $(NAME)

all: $(NAME)

$(MLX) :
		@make -C $(MLX_PATH)

$(LIBFT) :
		@make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJS)
	@make clean -C mlx
	@make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all
