# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 18:51:32 by ahmez-za          #+#    #+#              #
#    Updated: 2022/05/21 20:36:28 by ahmez-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c push_swap_helper.c  push_swap_helper2.c push_swap_helper3.c parsing_input.c push_to_stack_b.c push_to_stack_b_helpers.c push_to_stack_a.c sort_three_five.c 
NAME = push_swap
LIBFT = ./libft/libft.a
# FTPRINTF = ./ft_printf/libftprintf.a
CC = gcc 
# CFLAGS = -Wall -Wextra -Werror
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