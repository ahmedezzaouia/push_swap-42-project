/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:16:02 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/22 19:22:20 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_list_node **head_stack_1, \
		t_list_node **head_stack_2, char stack)
{
	t_list_node	*new;
	t_list_node	*temp;

	new = malloc(sizeof(t_list_node));
	if (!new)
		return ;
	if (!head_stack_1)
		return ;
	temp = *head_stack_1;
	new->data = (*head_stack_1)->data;
	new->index = (*head_stack_1)->index;
	new->next = NULL;
	*head_stack_1 = (*head_stack_1)->next;
	free(temp);
	lstadd_front(head_stack_2, new);
	if (stack == 'a')
		print_instructions("pa");
	else if (stack == 'b')
		print_instructions("pb");
}

void	swap_stack(t_list_node **head, char stack)
{
	t_list_node	*first;
	t_list_node	*second;

	if (get_list_size(*head) <= 1)
		return ;
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

void	rotat_stack(t_list_node **head_stack, char stack)
{
	t_list_node	*temp;

	if (get_list_size(*head_stack) <= 1)
		return ;
	temp = *head_stack;
	while (temp->next)
		temp = temp->next;
	temp->next = *head_stack;
	*head_stack = (*head_stack)->next;
	(temp->next)->next = NULL;
	if (stack == 'a')
		print_instructions("ra");
	else if (stack == 'b')
		print_instructions("rb");
}
