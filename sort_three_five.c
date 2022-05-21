/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:59:37 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 05:01:56 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(a_list **head)
{
    a_list *second;
    a_list *third;

    second = (*head)->next;
    third = second->next;
    if ((*head)->data > second->data && (*head)->data > third->data)
    {
        rotat_stack(head, NULL, 'a');
        second = (*head)->next;
        third = second->next;
    }
    if ((*head)->data > second->data)
    {

        swap_stack(head, 'a');
        second = (*head)->next;
        third = second->next;
    }
     if (second->data > third->data)
    {

        reverse_stack(head, NULL, 'a');
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

void sort_five_numbers(a_list **head_a, a_list **head_b)
{
    int i;
    int size;
    int min;
    int position;

    i = 0;

    while (i < 2)
    {
        size = get_list_size(*head_a);
        min = get_list_min(*head_a);
        position = get_min_or_max_postion(*head_a, min, 0);
        if ((*head_a)->data == min)
        {
            push_stack(head_a, head_b, 'b');
            i++;
            continue;
        }
        if (position > (size / 2))
        {
            min = size - position + 1;
            while (min != 0)
            {
                reverse_stack(head_a, NULL, 'a');
                min--;
            }
        }
        else
            rotat_stack(head_a, NULL, 'a');

        push_stack(head_a, head_b, 'b');
        i++;
    }
    sort_three(head_a);
    push_stack(head_a, head_b, 'a');
    push_stack(head_a, head_b, 'a');
    print_instructions(NULL);
}