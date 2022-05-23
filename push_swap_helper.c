/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:22:00 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/23 13:25:50 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_sort(t_list_node *head_stack_a)
{
	if (!head_stack_a)
		return (0);
	while (head_stack_a->next)
	{
		if (head_stack_a->data > (head_stack_a->next)->data)
		{
			return (0);
		}
		head_stack_a = head_stack_a->next;
	}
	return (1);
}

void	reverse_stack(t_list_node **head_stack, char stack)
{
	t_list_node	*last;
	t_list_node	*temp;
	t_list_node	*temp2;

	last = NULL;
	temp = *head_stack;
	if (get_list_size(*head_stack) <= 1)
		return ;
	while (temp->next)
	{
		temp2 = temp;
		temp = temp->next;
	}
	lstadd_front(head_stack, temp);
	temp2->next = NULL;
	if (stack == 'a')
		print_instructions("rra");
	else if (stack == 'b')
		print_instructions("rrb");
}

int	get_list_min(t_list_node *head)
{
	int	min;

	min = head->data;
	while (head)
	{
		if (head->data < min)
			min = head->data;
		head = head->next;
	}
	return (min);
}

int	get_list_max_index(t_list_node *head)
{
	int	max;

	max = head->index;
	if (get_list_size(head) == 1)
		return (max);
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	return (max);
}

int	get_min_or_max_postion(t_list_node *head, int value, int is_index)
{
	int	postion;

	postion = 1;
	while (head)
	{
		if (head->index == value && is_index)
			return (postion);
		if (head->data == value && !is_index)
			return (postion);
		postion += 1;
		head = head->next;
	}
	return (-1);
}
