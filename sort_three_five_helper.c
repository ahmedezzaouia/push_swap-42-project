/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_five_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:35:38 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 16:41:08 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three__rotate_helper(a_list **head, a_list **s, a_list **t)
{
	rotat_stack(head, NULL, 'a');
	*s = (*head)->next;
	*t = (*s)->next;
}

void	sort_three_swap_helper2(a_list **head, a_list **second, a_list **third)
{
	swap_stack(head, 'a');
	*second = (*head)->next;
	*third = (*second)->next;
}
