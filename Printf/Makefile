# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 13:53:04 by hari              #+#    #+#              #
#    Updated: 2024/08/14 23:56:46 by hrasolof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_strlen.c \
	ft_putnbr.c \
	ft_putnbr_u.c \
	ft_dec_to_hex.c \
	dec_to_hex.c \
	adr_to_str.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY : all clean fclean all
