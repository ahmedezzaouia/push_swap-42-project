
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

typedef struct s_help {
    int med;
    int range_min;
    int range_max;
    int s;
    int size;
    int chunk;

} t_vrls;


/*********************************************************************/
int get_list_size(a_list *head);
void lstadd_front(a_list **head, a_list *new);
void push_stack(a_list **head_stack_a, a_list **head_stack_b, char stack);
void swap_stack(a_list **head, char stack);
void rotat_stack(a_list **head_stack_a, a_list **head_stack_b, char stack);
void lstadd_back(a_list **head, a_list *new);
void reverse_stack(a_list **head_stack_a, a_list **head_stack_b, char stack);
int get_list_min(a_list *head);
int get_list_max_index(a_list *head);
int get_min_or_max_postion(a_list *head, int value, int is_index);
void print_list(a_list *head, char stack);

/**********************************************************************/
void	print_list(a_list *head, char stack);
void	sort_three__rotate_helper(a_list **head, a_list **s, a_list **t);
void	sort_three_swap_helper2(a_list **head, a_list **second, a_list **third);
void sort_three(a_list **head);
void sort_five_numbers(a_list **head_a, a_list **head_b);

/*********************************************************************/

void    ft_sort_int_tab(int *tab, int size);
void	print_instructions(char *instruct);
int     position(a_list *a, int size, int min, int max);
void    check_deplicate(a_list *head);
void    add_node(int data, a_list **head);
int     check_stack_sort(a_list *head_stack_a);
int	    *parsing_input(char **argv, int ac, a_list **head_a);
/******************* Push from A to B ********************************/
int     calculate_chunk(a_list *head_stack_a);
void    range_small(a_list **head_a, a_list **head_b, int *to_be_pushed, t_vrls *my_variables);
void    range_big(a_list **head_a, a_list **head_b, int *to_be_pushed, t_vrls *my_variables);
void    calc_ranges(t_vrls *my_variables);
void    sort_three(a_list **head);
void    sort_and_indexing(a_list **head_a, a_list **head_b, int *array);
void    pick_in_range(t_vrls *my_variables, a_list **head_a, a_list **head_b);
void    push_from_a_to_b(a_list **head_a, a_list * *head_b, int *array, t_vrls *my_variables);

/******************* Push to Stack A ********************************/
int	    is_max_exist(int value, a_list *head);
int	    get_last_index(a_list *head);
void	do_that_when_max_not_head(a_list **a, a_list **b, int *memory);
void	push_to_stack_a(a_list **a, a_list **b, int size);



#endif