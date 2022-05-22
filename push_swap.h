/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:48:09 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/22 21:21:22 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 4

typedef struct Node {
	int			data;
	int			index;
	struct Node	*next;
}	t_list_node;

typedef struct s_help {
	int	med;
	int	range_min;
	int	range_max;
	int	s;
	int	size;
	int	chunk;

}	t_vrls;

void	print_error(void);
/*********************************************************************/
int		get_list_size(t_list_node *head);
void	lstadd_front(t_list_node **head, t_list_node *new);
void	push_stack(t_list_node **head_stack_1,
			t_list_node **head_stack_2, char stack);
void	swap_stack(t_list_node **head, char stack);
void	rotat_stack(t_list_node **head_stack, char stack);
void	lstadd_back(t_list_node **head, t_list_node *new);
void	reverse_stack(t_list_node **head_stack, char stack);
int		get_list_min(t_list_node *head);
int		get_list_max_index(t_list_node *head);
int		get_min_or_max_postion(t_list_node *head, int value, int is_index);
void	print_list(t_list_node *head, char stack);

/**********************************************************************/
void	print_list(t_list_node *head, char stack);
void	sort_three__rotate_helper(t_list_node **head,
			t_list_node **s, t_list_node **t);
void	sort_three_swap_helper2(t_list_node **head,
			t_list_node **second, t_list_node **third);
void	sort_three(t_list_node **head);
void	sort_five_numbers(t_list_node **head_a, t_list_node **head_b);

/*********************************************************************/

void	ft_sort_int_tab(int *tab, int size);
void	print_instructions(char *instruct);
int		position(t_list_node *a, int size, int min, int max);
void	check_deplicate(t_list_node *head);
void	add_node(int data, t_list_node **head);
int		check_stack_sort(t_list_node *head_stack_a);
int		*parsing_input(char **argv, int ac, t_list_node **head_a);

/******************* Push from A to B ********************************/
int		calculate_chunk(t_list_node *head_stack_a);
void	range_small(t_list_node **head_a, t_list_node **head_b,
			int *to_be_pushed, t_vrls *my_variables);
void	range_big(t_list_node **head_a, t_list_node **head_b,
			int *to_be_pushed, t_vrls *my_variables);
void	calc_ranges(t_vrls *my_variables);
void	sort_three(t_list_node **head);
void	sort_and_indexing(t_list_node **head_a, int *array);
void	pick_in_range(t_vrls *my_variables,
			t_list_node **head_a, t_list_node **head_b);
void	push_from_a_to_b(t_list_node **head_a,
			t_list_node **head_b, int *array, t_vrls *my_variables);

/******************* Push to Stack A ********************************/
int		is_max_exist(int value, t_list_node *head);
int		get_last_index(t_list_node *head);
void	do_that_when_max_not_head(t_list_node **a,
			t_list_node **b, int *memory);
void	push_to_stack_a(t_list_node **a, t_list_node **b, int size);

int		ft_is_new_line(char *save);
char	*ft_get_line(char *save);
char	*get_next_line(int fd);

#endif