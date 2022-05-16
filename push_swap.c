/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:10:48 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/16 16:31:48 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_deplicate(a_list *head)
{
    a_list *temp;

    while (head)
    {
        temp = head->next;
        ;
        while (temp)
        {
            if (head->data == temp->data)
            {
                printf("Error\n");
                exit(1);
            }
            temp = temp->next;
        }
        head = head->next;
    }
}

int *parsing_Input(char **argv, int ac)
{
    int i;
    int j;
    int *init_nums;

    i = 1;
    j = 0;
    init_nums = malloc(sizeof(int) * ac);
    if (!init_nums)
        return (NULL);
    while (argv[i])
    {
        init_nums[j] = ft_atoi(argv[i]);
        i++;
        j++;
    }
    return (init_nums);
}

void add_node(int data, a_list **head)
{
    a_list *new;
    a_list *temp;
    int i;

    i = 0;
    new = malloc(sizeof(a_list));
    if (!new)
        return;
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

void lstadd_front(a_list **head, a_list *new)
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
        printf("sa\n");
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
        printf("sb\n");

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
        printf("sa\n");
    else if (stack == 'b')
        printf("sb\n");
    else if (stack == 0)
        printf("ss\n");
}

void rotat_stack(a_list **head_stack_a, a_list **head_stack_b, char stack)
{
    a_list *temp;
    
    if (stack == 'a' || stack == 0)
    {
        if (!*head_stack_a)
            return;
        temp = *head_stack_a;
        while (temp->next)
            temp = temp->next;
        temp->next = *head_stack_a;
        *head_stack_a = (*head_stack_a)->next;
        (temp->next)->next = NULL;
        if (stack != 0)
            printf("ra\n");
    }
    if (stack == 'b' || stack == 0)
    {
        if (!*head_stack_b)
            return;
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

int check_stack_sort(a_list *head_stack_a)
{
    while (head_stack_a->next)
    {
        if (head_stack_a->data > (head_stack_a->next)->data)
        {
            printf("stack is not sorted\n");
            return (0);
        }
        head_stack_a = head_stack_a->next;
    }
    printf("stack sorted\n");
    return (1);
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

    last = NULL;
    temp = NULL;
    if (stack == 'a' || stack == 0)
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
    else if (stack == 'b' || stack == 0)
    {
        temp = *head_stack_b;
        while (temp->next)
            temp = temp->next;
        last = temp;
        while (*head_stack_a != last)
        {
            lstadd_back(head_stack_b, *head_stack_b);
            temp = temp->next;
        }
    }

    if (stack == 'a')
        printf("rra\n");
    else if (stack == 'b')
        printf("rrb\n");
    else if (stack == 0)
        printf("rrr\n");
}

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
}

int    get_list_size(a_list *head)
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
    while (head)
    {
        if (head->index > max)
            max = head->index;
        head = head->next;
    }
    return (max);
}

int get_min_or_max_postion(a_list *head, int min)
{
    int postion;

    postion = 1;
    while (head)
    {
        if (head->data == min)
            return (postion);    
        head = head->next;
        postion++;
    }
    return (-1);
}
void    print_list(a_list *head, char stack)
{
        
    while (head)
    {
        printf("stack %c = %d index == %d\n",stack, head->data,head->index);
        head = head->next;
    }
}

void    sort_five_numbers(a_list **head_a, a_list **head_b)
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
        position = get_min_or_max_postion(*head_a, min);
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
    
}

void    re_push_to_stack_a(a_list **head_a, a_list **head_b)
{
    int max;
    int pos;
    int med;

    while (*head_b)
    {
        max = get_list_max_index(*head_b);
        pos = get_min_or_max_postion(*head_b, max) - 1;
        med = get_list_size(*head_b) - 1 / 2;
        if (pos <= med)
        {
            while ((*head_b)->index != max)
            {
                // printf("MAX = %d || POS == %d || med == %d\n",max, pos, med);
                // print_list(*head_b, 'A');
                rotat_stack(head_a, head_b, 'b');
            }
            
        }
        else if (pos > med)
        {
            while ((*head_b)->index != max)
            {
                reverse_stack(head_a, head_b, 'b');
            }
        }
        push_stack(head_a, head_b, 'a');
        
    }
    
    
}




int main(int ac, char **argv)
{
    int i;
    int *array;
    a_list *head_stack_a;
    a_list *head_stack_b;
    int range_min;
    int range_max;
    int chunk;

    i = 0;
    head_stack_a = NULL;
    head_stack_b = NULL;
    array = parsing_Input(argv, ac);

    while (i < ac - 1)
        add_node(array[i++], &head_stack_a);

    check_deplicate(head_stack_a);

    a_list *temp, *da;
    temp = head_stack_a;
   
    print_list(head_stack_a, 'A');
    printf("\n\n");

    if (ac == 4)
        sort_three(&head_stack_a);
    else if (ac == 6)
        sort_five_numbers (&head_stack_a, &head_stack_b);
    else if (ac > 6)
    {
        // sort array 
        i = 0;
        ft_sort_int_tab(array, get_list_size(head_stack_a));
        while (i < get_list_size(head_stack_a))
            printf("%d ",array[i++]);
        
        printf("\n");
        // index the linked list
        i = 0;
        while (i < get_list_size(head_stack_a))
        {
            temp = head_stack_a;
            while (temp)
            {
                if (temp->data == array[i])
                {
                    temp->index = i;
                    break ;
                }
                temp = temp->next;
            }
            i++;
        }
        // push chunks to stack B
        if (get_list_size(head_stack_a) <= 10)
            chunk = 2;
        if (get_list_size(head_stack_a) > 10)
            chunk = 15;
        else if (get_list_size(head_stack_a) > 150)
            chunk = 30;
        
        range_max = (get_list_size(head_stack_a) - 1) / 2 + chunk;
        range_min = (get_list_size(head_stack_a) - 1) / 2 - chunk;
 
        while (head_stack_a)
        {
            temp = head_stack_a;
            while (temp)
            {
                // between : range_min <= el <= med 
                if (temp->index >= range_min && (temp->index <= (get_list_size(head_stack_a) - 1) / 2))
                {
                   push_stack(&head_stack_a, &head_stack_b, 'b');
                   rotat_stack(&head_stack_a, &head_stack_b,'b');
                   
                }
                // between : range_max >= el > med 
                else if (temp->index >= (get_list_size(head_stack_a) - 1) / 2 && temp->index <= range_max)
                {
                   push_stack(&head_stack_a, &head_stack_b, 'b');
                }
                else
                  rotat_stack(&head_stack_a, &head_stack_b,'a');

                
                temp = temp->next;
            
            }
            range_max += 2;
            range_min -= 2;
            if (range_min < -1) range_min = -1;
            // printf("range max == %d\n",range_max);
            // printf("range min == %d\n",range_min);
            // printf("\nloop\n\n");
        }
        // Repush to stack A

        re_push_to_stack_a(&head_stack_a, &head_stack_b);

    }
    print_list(head_stack_b, 'B');
    printf("\n\n");
    print_list(head_stack_a, 'A');
    // printf("\n\n");
    // print_list(head_stack_b, 'B');

}
