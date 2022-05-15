/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:10:48 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/15 00:06:33 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




int*    parsing_Input(char **argv, int ac)
{
    int i;
    int j;
    int *init_nums;

    i = 1;
    j = 0;
    init_nums = malloc(sizeof(int) * ac);
    if (init_nums == NULL)
        return (NULL);
    while (argv[i])
    {
        init_nums[j] = ft_atoi(argv[i]);
        i++;
        j++;
    }
    return (init_nums);
}

void    add_node(int data, a_list **head)
{
    a_list *new;
    a_list *temp;
    int     i;

    i = 0;
    new = malloc(sizeof(a_list));
    if (!new)
        return ;
    new->data = data;
    new->next = NULL;
    if (*head == NULL)
        *head = new;
    else
    {
        temp = *head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void	lstadd_front(a_list **head, a_list *new)
{
	if (new)
	{
		new->next = (*head);
		*head = new;
	}
}

void    push_stack(a_list **head_stack_a, a_list **head_stack_b, char stack)
{

    a_list *new;
    a_list *temp;

    new = malloc(sizeof(a_list));
    if (!new)
        return ;
    if (stack == 'a')
    {
        new->data = (*head_stack_b)->data;
        new->next = NULL;
        *head_stack_b = (*head_stack_b)->next;
        free (temp);
        lstadd_front(head_stack_a , new);
    }
    else
    {
        new->data =(*head_stack_a)->data;
        new->next = NULL;
        temp = *head_stack_a;
        *head_stack_a = (*head_stack_a)->next;
        free (temp);
        lstadd_front(head_stack_b, new);
    }
   
}

void    swap_stack(a_list **head)
{
    a_list *first;   
    a_list *second;   
    first = *head;

    second = first->next;
    first->next = second->next;
    second->next = first;
    *head = second;
}

void    rotat_stack(a_list **head_stack_a, a_list **head_stack_b, char stack)
{
    a_list  *temp;

    if (stack == 'a' || stack == 0)
    {
        if (!*head_stack_a)
            return ;
        temp = *head_stack_a;
        while (temp->next)
            temp = temp->next;
        temp->next = *head_stack_a;
        *head_stack_a = (*head_stack_a)->next;
        (temp->next)->next = NULL;
        if (stack != 0)
            printf("ra\n");
    }
    if(stack == 'b' || stack == 0)
    {
        if (!*head_stack_b)
            return ;
        temp = *head_stack_b;
        while (temp->next)
            temp = temp->next;
        temp->next = *head_stack_b;
        *head_stack_b = (*head_stack_b)->next;
        (temp->next)->next = NULL;
        if (stack != 0)
            printf("rb\n");
    }
    if (stack == 0)
            printf("rr\n");
}

void    check_stack_sort(a_list *head_stack_a)
{
    while (head_stack_a->next)
    {
        if ( head_stack_a->data > (head_stack_a->next)->data)
        {
            printf("stack is not sorted\n");
            exit(1);
        }
        head_stack_a = head_stack_a->next; 
    }
    printf("stack sorted\n");

}

void    lstadd_back(a_list **head, a_list *new)
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


void    reverse_stack(a_list **head_stack_a, a_list **head_stack_b, char stack)
{
    a_list  *last;
    a_list  *temp;
    
    last = NULL;
    temp = NULL;
    if (stack == 'a')
    {
        temp = *head_stack_a;
        while (temp->next)
            temp = temp->next;
        last = temp;
        while (*head_stack_a != last)
        {
            lstadd_back(head_stack_a, *head_stack_a);
            temp = temp->next;
        }
    }
    else
    {

    }
}

int main(int ac, char **argv)
{
    int i;
    int *array;
    a_list *head_stack_a;
    a_list *head_stack_b;
    
    i = 0;
    head_stack_a = NULL;
    head_stack_b = NULL;
    array = parsing_Input(argv, ac);
    while (i < ac - 1)
        add_node(array[i++], &head_stack_a);

    a_list *temp, *da;

    temp = head_stack_a;
    while (temp)
    {
        printf("before A = %d\n",temp->data);
        temp = temp->next;
    }
    
    printf("\n\n");

    // swap_stack(&head_stack_a);
    // push_stack(&head_stack_a, &head_stack_b, 'b');
    // push_stack(&head_stack_a, &head_stack_b, 'b');
    // push_stack(&head_stack_a, &head_stack_b, 'b');
    // push_stack(&head_stack_a, &head_stack_b, 'b');

    rotat_stack(&head_stack_a, &head_stack_b, 'b');
    // check_stack_sort(head_stack_a);
    // reverse_stack(&head_stack_a, &head_stack_b, 'a');

  
    temp = head_stack_a;
    while (temp)
    {
        printf("after A = %d\n",temp->data);
        temp = temp->next;
    }


    printf("\n\n");



    da = head_stack_b;
    while (da)
    {
        printf("stack B = %d\n",da->data);
        da = da->next;
    }
}
