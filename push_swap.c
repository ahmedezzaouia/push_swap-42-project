/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:10:48 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/22 22:15:37 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_numbers(t_list_node **head_stack_a, t_list_node **head_stack_b)
{
	int	size;

	size = get_list_size(*head_stack_b);
	while (*head_stack_b)
		push_to_stack_a(head_stack_a, head_stack_b, size);
	while (!check_stack_sort(*head_stack_a))
		reverse_stack(head_stack_a, 'a');
}

int	main(int ac, char **argv)
{
	int				*array;
	int				size;
	t_list_node		*head_stack_a;
	t_list_node		*head_stack_b;
	t_vrls			my_variables;

	if (ac == 1)
		exit(0);
	head_stack_a = NULL;
	head_stack_b = NULL;
	array = parsing_input(argv, ac, &head_stack_a);
	size = get_list_size(head_stack_a);
	if (check_stack_sort(head_stack_a) == 1)
		exit (0);
	else if (size == 2)
		swap_stack(&head_stack_a, 'a');
	else if (size == 3)
		sort_three(&head_stack_a);
	else if (size > 3)
	{
		push_from_a_to_b(&head_stack_a, &head_stack_b, array, &my_variables);
		sort_big_numbers(&head_stack_a, &head_stack_b);
	}
	print_instructions(NULL);
}
