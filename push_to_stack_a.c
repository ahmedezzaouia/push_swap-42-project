/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:05:39 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 21:22:41 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_max_exist(int value, t_list_node *head)
{
	while (head)
	{
		if (head->index == value)
			return (1);
		head = head->next;
	}
	return (0);
}

int	get_last_index(t_list_node *head)
{
	while (head->next)
		head = head->next;
	return (head->index);
}

void	do_that_when_max_not_head(t_list_node **a, t_list_node **b, int *memory)
{
	int	pos;

	if (*memory == 0 || (*b)->index > get_last_index(*a))
	{
		push_stack(a, b, 'a');
		rotat_stack(a, b, 'a');
		(*memory)++;
	}
	else
	{
		pos = get_min_or_max_postion(*b, get_list_max_index(*b), 1);
		if (pos < get_list_size(*b) / 2)
			rotat_stack(a, b, 'b');
		else
			reverse_stack(a, b, 'b');
	}
}

void	push_to_stack_a(t_list_node **a, t_list_node **b, int size)
{
	static int	i = 1;
	static int	memory = 0;

	if (is_max_exist(size - i, *b))
	{
		if ((*b)->index == size - i)
		{
			push_stack(a, b, 'a');
			i++;
		}
		else
			do_that_when_max_not_head(a, b, &memory);
	}
	else if (memory)
	{
		reverse_stack(a, b, 'a');
		i++;
		memory--;
	}
}
