/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:45:22 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 15:45:36 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_back(a_list **head, a_list *new)
{
	a_list	*temp;

	if (new == NULL)
		return ;
	temp = (*head);
	while (temp->next != NULL)
		temp = temp->next;
	(*head) = (*head)->next;
	new->next = NULL;
	temp->next = new;
}
