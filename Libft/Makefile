# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 09:55:22 by hrasolof          #+#    #+#              #
#    Updated: 2024/08/19 17:03:20 by hrasolof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
 		ft_isprint.c \
 		ft_strlen.c \
 		ft_memset.c \
 		ft_bzero.c \
 		ft_memcpy.c \
 		ft_memmove.c \
 		ft_strlcpy.c \
 		ft_strlcat.c \
 		ft_toupper.c \
 		ft_tolower.c \
 		ft_strchr.c \
 		ft_strrchr.c \
 		ft_strncmp.c \
 		ft_memchr.c \
 		ft_memcmp.c \
 		ft_strnstr.c \
		ft_atoi.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_striteri.c \
		ft_split.c \
		ft_strmapi.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstadd_front_bonus.c  

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

bonus: $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o: %.c
		cc $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY : all clean fclean all
