/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_A_to_be_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 03:31:28 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 03:31:40 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk(a_list *head_stack_a)
{
	if (get_list_size(head_stack_a) <= 10)
		return (2);
	else if (get_list_size(head_stack_a) < 150)
		return (12);
	else
		return (30);
}

void	range_small(a_list **head_stack_a, a_list **head_stack_b, \
int *to_be_pushed, t_vrls *my_variables)
{
	push_stack(head_stack_a, head_stack_b, 'b');
	rotat_stack(head_stack_a, head_stack_b, 'b');
	if ((*head_stack_a)->index != my_variables->size / 2)
		(*to_be_pushed)--;
	(my_variables->s)--;
}

void	range_big(a_list **head_stack_a, a_list **head_stack_b, \
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