/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:22:00 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 14:35:24 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_stack_a(a_list **head_stack_a, a_list **head_stack_b)
{
	a_list	*temp;
	a_list	*temp2;

	temp = *head_stack_a;
	while (temp->next)
	{
		temp2 = temp;
		temp = temp->next;
	}
	lstadd_front(head_stack_a, temp);
	temp2->next = NULL;
}

void	reverse_stack(a_list **head_stack_a, a_list **head_stack_b, char stack)
{
	a_list	*last;
	a_list	*temp;
	a_list	*temp2;

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

int	get_list_min(a_list *head)
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

int	get_list_max_index(a_list *head)
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

int	get_min_or_max_postion(a_list *head, int value, int is_index)
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
