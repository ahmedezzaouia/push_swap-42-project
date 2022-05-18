# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 18:51:32 by ahmez-za          #+#    #+#              #
#    Updated: 2022/05/17 22:39:56 by ahmez-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c push_swap_helper.c
NAME = push_swap
LIBFT = ./libft/libft.a
# FTPRINTF = ./ft_printf/libftprintf.a
CC = gcc
CFLAGS = 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	cd libft && make && cd ..
	# cd ft_printf && make && cd ..
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(FTPRINTF)  -o $(NAME)

clean:
	cd libft && make clean && cd ..
	rm -f $(OBJS)

fclean:clean
	cd libft && make fclean && cd ..
	rm -f $(NAME)
re: fclean all