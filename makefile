# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 18:51:32 by ahmez-za          #+#    #+#              #
#    Updated: 2022/05/23 13:25:00 by ahmez-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c push_swap_helper.c  push_swap_helper2.c push_swap_helper3.c parsing_input.c push_to_stack_b.c push_to_stack_b_helpers.c push_to_stack_a.c sort_three_five.c
BONUS_SRCS = checker_bonus.c push_swap_helper.c push_swap_helper2.c push_swap_helper3.c parsing_input.c push_to_stack_b.c push_to_stack_b_helpers.c push_to_stack_a.c sort_three_five.c
NAME = push_swap
BONUS_NAME = checker
LIBFT = ./libft/libft.a
FTPRINTF = ./ft_printf/libftprintf.a
GNL = get_next_line.c get_next_line_utils.c
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	cd libft && make && cd ..
	cd ft_printf && make && cd ..
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(FTPRINTF) -o $(NAME) 

$(BONUS_NAME) : 
	cd libft && make && cd ..
	cd ft_printf && make && cd ..
	$(CC) $(CFLAGS) $(BONUS_SRCS) ${GNL} ${LIBFT} ${FTPRINTF} -o $(BONUS_NAME) 

bonus: $(BONUS_NAME)

clean:
	cd libft && make clean && cd ..
	rm -f $(OBJS)

fclean:clean
	cd libft && make fclean && cd ..
	rm -f $(NAME) ${BONUS_NAME}
	
re: fclean all