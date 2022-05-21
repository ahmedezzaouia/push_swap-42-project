/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:13:45 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 04:58:33 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_list_size(a_list *head)
{
    int size;

    size = 0;
    while (head)
    {
        size++;
        head = head->next;
    }
    return (size);
}




void lstadd_front(a_list **head, a_list *new)
{
    if (new)
    {
        new->next = (*head);
        *head = new;
    }
}

void push_stack(a_list **head_stack_a, a_list **head_stack_b, char stack)
{

    a_list *new;
    a_list *temp;

    new = malloc(sizeof(a_list));
    if (!new)
        return;
    if (stack == 'a')
    {
        temp = *head_stack_b;
        new->data = (*head_stack_b)->data;
        new->index = (*head_stack_b)->index;
        new->next = NULL;
        *head_stack_b = (*head_stack_b)->next;
        free(temp);
        lstadd_front(head_stack_a, new);
        // printf("pa\n");
        print_instructions("pa");

    }
    else if (stack == 'b')
    {
        temp = *head_stack_a;
        new->data = (*head_stack_a)->data;
        new->index = (*head_stack_a)->index;
        new->next = NULL;
        *head_stack_a = (*head_stack_a)->next;
        free(temp);
        lstadd_front(head_stack_b, new);
        // printf("pb\n");
        print_instructions("pb");

    }
}

void swap_stack(a_list **head, char stack)
{
    a_list *first;
    a_list *second;
    first = *head;

    second = first->next;
    first->next = second->next;
    second->next = first;
    *head = second;
    if (stack == 'a')
        // printf("sa\n");
        print_instructions("sa");

    else if (stack == 'b')
        // printf("sb\n");
        print_instructions("sb");

    // else if (stack == 0)
    //     printf("ss\n");
}

void rotat_stack(a_list **head_stack_a, a_list **head_stack_b, char stack)
{
    a_list *temp;

    if (stack == 'a')
    {
        if (get_list_size(*head_stack_a) <= 1)
            return;
        temp = *head_stack_a;
        while (temp->next)
            temp = temp->next;
        temp->next = *head_stack_a;
        *head_stack_a = (*head_stack_a)->next;
        (temp->next)->next = NULL;
        print_instructions("ra");
    }
    if (stack == 'b')
    {
        if (get_list_size(*head_stack_b) <= 1)
            return;
        temp = *head_stack_b;
        while (temp->next)
            temp = temp->next;
        temp->next = *head_stack_b;
        *head_stack_b = (*head_stack_b)->next;
        (temp->next)->next = NULL;
        print_instructions("rb");

    }
    // if (stack == 0)
    //     printf("rr\n");
}



void lstadd_back(a_list **head, a_list *new)
{
    a_list *temp;

    if (new == NULL)
        return;

    temp = (*head);
    while (temp->next != NULL)
        temp = temp->next;
    (*head) = (*head)->next;
    new->next = NULL;
    temp->next = new;
}

void reverse_stack(a_list **head_stack_a, a_list **head_stack_b, char stack)
{
    a_list *last;
    a_list *temp;
    a_list *temp2;

    last = NULL;
    temp = NULL;
    if (stack == 'a')
    {
        temp = *head_stack_a;

        while (temp->next)
        {
            temp2 = temp;
            temp = temp->next;
        }
        lstadd_front(head_stack_a, temp);
        temp2->next = NULL;
    }
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


int get_list_min(a_list *head)
{
    int min;

    min = head->data;
    while (head)
    {
        if (head->data < min)
            min = head->data;
        head = head->next;
    }
    return (min);
}

int get_list_max_index(a_list *head)
{
    int max;

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

int get_min_or_max_postion(a_list *head, int value, int is_index)
{
    int postion;


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
void print_list(a_list *head, char stack)
{

    while (head)
    {
        printf("stack %c = %d index == %d\n", stack, head->data, head->index);
        head = head->next;
    }
}