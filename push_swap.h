
#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H
# include "./libft/libft.h"
// # include "./ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>


typedef struct Node {
    int data;
    int index;
    struct Node* next;
} a_list;

int	my_abs(int n);


void    ft_sort_int_tab(int *tab, int size);
void	print_instructions(char *instruct);
int     position(a_list *a, int size, int min, int max);
void    check_deplicate(a_list *head);
void    add_node(int data, a_list **head);
int check_stack_sort(a_list *head_stack_a);
int *parsing_Input(char **argv, int ac, a_list **head_a);



#endif