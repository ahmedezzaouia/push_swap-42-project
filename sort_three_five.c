/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:59:37 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/22 18:58:26 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three__rotate_helper(t_list_node **head, \
		t_list_node **s, t_list_node **t)
{
	rotat_stack(head, 'a');
	*s = (*head)->next;
	*t = (*s)->next;
}

void	sort_three_swap_helper2(t_list_node **head, \
		t_list_node **second, t_list_node **third)
{
	swap_stack(head, 'a');
	*second = (*head)->next;
	*third = (*second)->next;
}

void	sort_three(t_list_node **head)
{
	t_list_node	*second;
	t_list_node	*third;

	second = (*head)->next;
	third = second->next;
	if ((*head)->data > second->data && (*head)->data > third->data)
		sort_three__rotate_helper(head, &second, &third);
	if ((*head)->data > second->data)
		sort_three_swap_helper2(head, &second, &third);
	if (second->data > third->data)
	{
		reverse_stack(head, 'a');
		second = (*head)->next;
		third = second->next;
	}
	if ((*head)->data > second->data)
	{
		swap_stack(head, 'a');
		second = (*head)->next;
		third = second->next;
	}
	print_instructions(NULL);
}
