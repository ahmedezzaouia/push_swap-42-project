/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:16:02 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 15:45:15 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack_helper(a_list **head_a, a_list **head_b, a_list	*new)
{
	a_list	*temp;

	temp = *head_b;
	new->data = (*head_b)->data;
	new->index = (*head_b)->index;
	new->next = NULL;
	*head_b = (*head_b)->next;
	free(temp);
	lstadd_front(head_a, new);
	print_instructions("pa");
}

void	push_stack(a_list **head_stack_a, a_list **head_stack_b, char stack)
{
	a_list	*new;
	a_list	*temp;

	new = malloc(sizeof(a_list));
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

void	swap_stack(a_list **head, char stack)
{
	a_list	*first;
	a_list	*second;

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

void	rotat_stack_helper(a_list **head_stack_a, a_list **head_stack_b)
{
	a_list	*temp;

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

void	rotat_stack(a_list **head_stack_a, a_list **head_stack_b, char stack)
{
	a_list	*temp;

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
