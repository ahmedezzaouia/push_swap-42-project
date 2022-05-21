/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_A_to_B.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:50:17 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 03:32:10 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing_stack(a_list **head_stack_a, int *array)
{
	int		i;
	a_list	*temp;

	i = 0;
	while (i < get_list_size(*head_stack_a))
	{
		temp = *head_stack_a;
		while (temp)
		{
			if (temp->data == array[i])
			{
				temp->index = i;
				break ;
			}
			temp = temp->next;
		}
		i++;
	}
}

void	sort_and_indexing(a_list **head_a, a_list **head_b, int *array)
{
	ft_sort_int_tab(array, get_list_size(*head_a));
	indexing_stack(head_a, array);
}

void	pick_in_range(t_vrls *my_variables, a_list **head_a, a_list **head_b)
{
	a_list	*temp;
	int		to_be_pushed;

	to_be_pushed = 2 * my_variables->chunk;
	while (to_be_pushed && my_variables->s > 3)
	{
		temp = *head_a;
		if (temp->index >= my_variables->range_min && \
		(temp->index < (my_variables->size - 1) / 2))
			range_small(head_a, head_b, &to_be_pushed, my_variables);
		else if (temp->index >= (my_variables->size - 1) / 2 && \
		temp->index <= my_variables->range_max)
			range_big(head_a, head_b, &to_be_pushed, my_variables);
		else
			rotat_stack(head_a, head_b, 'a');
	}
}

void	push_from_a_to_b(a_list **head_a, a_list **head_b, \
int *array, t_vrls *my_variables)
{
	my_variables->chunk = calculate_chunk(*head_a);
	sort_and_indexing(head_a, head_b, array);
	my_variables->size = get_list_size(*head_a);
	my_variables->range_max = (my_variables->size - 1) / 2 \
	+ my_variables->chunk;
	my_variables->range_min = (my_variables->size - 1) / 2 \
	- my_variables->chunk;
	my_variables->s = my_variables->size;
	while (my_variables->s > 3)
	{
		pick_in_range(my_variables, head_a, head_b);
		calc_ranges(my_variables);
	}
	sort_three(head_a);
	print_instructions(NULL);
}
