
#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H
# include "./libft/libft.h"
// # include "./ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct Node {
    int data;
    int index;
    struct Node* next;
} a_list;


void ft_sort_int_tab(int *tab, int size);

#endif