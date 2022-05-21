/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:16:02 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 21:20:13 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack_helper(t_list_node **head_a, t_list_node **head_b, \
		t_list_node	*new)
{
	t_list_node	*temp;

	temp = *head_b;
	new->data = (*head_b)->data;
	new->index = (*head_b)->index;
	new->next = NULL;
	*head_b = (*head_b)->next;
	free(temp);
	lstadd_front(head_a, new);
	print_instructions("pa");
}

void	push_stack(t_list_node **head_stack_a, \
		t_list_node **head_stack_b, char stack)
{
	t_list_node	*new;
	t_list_node	*temp;

	new = malloc(sizeof(t_list_node));
	if (!new)
		return ;
	if (stack == 'a')
		push_stack_helper(head_stack_a, head_stack_b, new);
	else if (stack == 'b')
	{
		temp = *head_stack_a;
		new->data = (*head_stack_a)->data;
		new->index = (*head_stack_a)->index;
		new->next = NULL;
		*head_stack_a = (*head_stack_a)->next;
		free(temp);
		lstadd_front(head_stack_b, new);
		print_instructions("pb");
	}
}

void	swap_stack(t_list_node **head, char stack)
{
	t_list_node	*first;
	t_list_node	*second;

	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	if (stack == 'a')
		print_instructions("sa");
	else if (stack == 'b')
		print_instructions("sb");
}

void	rotat_stack_helper(t_list_node **head_stack_a, \
		t_list_node **head_stack_b)
{
	t_list_node	*temp;

	if (get_list_size(*head_stack_a) <= 1)
		return ;
	temp = *head_stack_a;
	while (temp->next)
		temp = temp->next;
	temp->next = *head_stack_a;
	*head_stack_a = (*head_stack_a)->next;
	(temp->next)->next = NULL;
	print_instructions("ra");
}

void	rotat_stack(t_list_node **head_stack_a, \
		t_list_node **head_stack_b, char stack)
{
	t_list_node	*temp;

	if (stack == 'a')
		rotat_stack_helper(head_stack_a, head_stack_b);
	if (stack == 'b')
	{
		if (get_list_size(*head_stack_b) <= 1)
			return ;
		temp = *head_stack_b;
		while (temp->next)
			temp = temp->next;
		temp->next = *head_stack_b;
		*head_stack_b = (*head_stack_b)->next;
		(temp->next)->next = NULL;
		print_instructions("rb");
	}
}
