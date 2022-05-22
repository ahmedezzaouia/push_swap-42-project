/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b_helpers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 03:31:28 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/22 19:07:26 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk(t_list_node *head_stack_a)
{
	if (get_list_size(head_stack_a) <= 10)
		return (2);
	else if (get_list_size(head_stack_a) < 150)
		return (12);
	else
		return (30);
}

void	range_small(t_list_node **head_stack_a, t_list_node **head_stack_b, \
int *to_be_pushed, t_vrls *my_variables)
{
	push_stack(head_stack_a, head_stack_b, 'b');
	rotat_stack(head_stack_b, 'b');
	if ((*head_stack_a)->index != my_variables->size / 2)
		(*to_be_pushed)--;
	(my_variables->s)--;
}

void	range_big(t_list_node **head_stack_a, t_list_node **head_stack_b, \
int *to_be_pushed, t_vrls *my_variables)
{
	push_stack(head_stack_a, head_stack_b, 'b');
	if ((*head_stack_a)->index != my_variables->size / 2)
		(*to_be_pushed)--;
	(my_variables->s)--;
}

void	calc_ranges(t_vrls *my_variables)
{
	my_variables->range_max += my_variables->chunk;
	my_variables->range_min -= my_variables->chunk;
	if (my_variables->range_max > (my_variables->size - 4))
	{
		my_variables->range_max = my_variables->size - 4;
		my_variables->range_min = 0;
	}
}
