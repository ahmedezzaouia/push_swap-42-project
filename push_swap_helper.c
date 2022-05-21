/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:22:00 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 21:14:17 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_stack_a(t_list_node **head_stack_a, t_list_node **head_stack_b)
{
	t_list_node	*temp;
	t_list_node	*temp2;

	temp = *head_stack_a;
	while (temp->next)
	{
		temp2 = temp;
		temp = temp->next;
	}
	lstadd_front(head_stack_a, temp);
	temp2->next = NULL;
}

void	reverse_stack(t_list_node **head_stack_a, t_list_node **head_stack_b, char stack)
{
	t_list_node	*last;
	t_list_node	*temp;
	t_list_node	*temp2;

	last = NULL;
	temp = NULL;
	if (stack == 'a')
		reverse_stack_a(head_stack_a, head_stack_b);
	else if (stack == 'b' )
	{
		temp = *head_stack_b;
		while (temp->next)
		{
			temp2 = temp;
			temp = temp->next;
		}
		lstadd_front(head_stack_b, temp);
		temp2->next = NULL;
	}
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
