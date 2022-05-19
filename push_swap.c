/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:10:48 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/19 17:26:40 by ahmez-za         ###   ########.fr       */
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

int check_stack_sort(a_list *head_stack_a)
{
    while (head_stack_a->next)
    {
        if (head_stack_a->data > (head_stack_a->next)->data)
        {
            // printf("stack is not sorted\n");
            return (0);
        }
        head_stack_a = head_stack_a->next;
    }
    // printf("stack sorted\n");
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

void re_push_to_stack_a(a_list **head_a, a_list **head_b)
{
    int max; // max = 5
    int pos; // pos = 3
    int pos2; // pos = 0
    int med; // med = 1
    static int down = 0;

    while (*head_b)
    {

        max = get_list_max_index(*head_b);
        pos = get_min_or_max_postion(*head_b, max, 1);
        pos2 = get_min_or_max_postion(*head_b,max - 1, 1);
        med = (get_list_size(*head_b) - 1) / 2;

        // printf("max == [%d]\n",max);
        // printf("pos == [%d]\n",pos);
        // printf("pos2 == [%d]\n",pos2);
        // printf("down == [%d]\n",down);

        if (pos2 < pos && pos2 != -1)
        {
            max--;
            pos = pos2;
        } 
        // printf("********taken pos == [%d]\n",pos);
        // printf("********take max == [%d]\n",max);
        // printf("\n\n");

        int x = pos;

        if (pos == 2)
        {
            swap_stack(head_b, 'b');
        } 
        else if (pos <= med)
        {
            while (x > 2 /*(*head_b)->index != max*/)
            {
                rotat_stack(head_a, head_b, 'b');
                x--;
            }
            if (x == 2)
                swap_stack(head_b, 'b');
        }

        else if (pos > med)
        {

            while ((*head_b)->index != max)
            {
                reverse_stack(head_a, head_b, 'b');
            }
        }
            
        if ((*head_a) && (*head_a)->next && ((*head_a)->index > (*head_a)->next->index))
            swap_stack(head_a, 'a');

        push_stack(head_a, head_b, 'a');
        // if (down == 1)
        // {
        //     swap_stack(head_a, 'a');
        //     down = 0;
        // }
        // else if(down == 0 && pos2 == pos)
        //     down = 1;
        
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
    int size;

    i = 0;
    head_stack_a = NULL;
    head_stack_b = NULL;
    array = parsing_Input(argv, ac);

    while (i < ac - 1)
        add_node(array[i++], &head_stack_a);

    check_deplicate(head_stack_a);

    a_list *temp, *da;
    temp = head_stack_a;


    if (ac == 4)
        sort_three(&head_stack_a);
    else if (ac == 6)
        sort_five_numbers (&head_stack_a, &head_stack_b);
    else if (ac > 6)
    {
        // sort array
        i = 0;
        ft_sort_int_tab(array, get_list_size(head_stack_a));

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
                    break;
                }
                temp = temp->next;
            }
            i++;
        }
       
        /******* push chunks to stack B  *****/
        if (get_list_size(head_stack_a) <= 10)
            chunk = 2;
        else if (get_list_size(head_stack_a) < 150)
            chunk = 12;
        else
            chunk = 30;
        size = get_list_size(head_stack_a);
        range_max = (size - 1) / 2 + chunk; // max = 5
        range_min = (size - 1) / 2 - chunk; // min  

        int to_be_pushed; 
        int s = size;
        while (/*head_stack_a*/ s > 5)
        {

            to_be_pushed = 2 * chunk;
            if (range_max == (size - 6))
                to_be_pushed = s;
            while  (to_be_pushed && /*head_stack_a*/ s > 5)
            {
                // temp = head_stack_a;
                // // between : range_min <= el < med  : small
                // if (temp->index >= range_min && (temp->index < (size - 1) / 2))
                // {
                //     push_stack(&head_stack_a, &head_stack_b, 'b');
                //     rotat_stack(&head_stack_a, &head_stack_b, 'b');
                //     if (temp->index != size / 2)
                //         to_be_pushed--;
                //     s--;
                // }
                // // between : range_max >= el => med  big
                // else if (temp->index >= (size - 1) / 2 && temp->index <= range_max)
                // {
                //     push_stack(&head_stack_a, &head_stack_b, 'b');
                //     if (temp->index != size / 2)
                //         to_be_pushed--;
                //     s--;
                // }
                
                // else
                // {
                //     rotat_stack(&head_stack_a, &head_stack_b, 'a');
                   
                // }
                //printf("%d\n", s);
                int p = position(head_stack_a, s, range_min, range_max);
                if (p == -1)
                    break;
                if (p <= get_list_size(head_stack_a) / 2)
                {
                    while (p-- > 1)
                        rotat_stack(&head_stack_a, &head_stack_b, 'a');   
                }
                else
                {
                    p = size - p + 1;
                    while (p-- > 1)
                        reverse_stack(&head_stack_a, &head_stack_b, 'a');   
                }
                push_stack(&head_stack_a, &head_stack_b, 'b');
                if (head_stack_b->index > (size - 1) / 2)
                    rotat_stack(&head_stack_a, &head_stack_b, 'b');
                s--;
            }

                    range_max += chunk;
                    range_min -= chunk;

                    if (range_max > (size - 6))
                    {
                        range_max = size - 6;
                        range_min = 0;
                    }
                    // if (range_min < -1)
                    //     range_min = -1;
            
        }
        // printf("%d\n", range_min);
        // printf("%d\n", range_max);
        sort_five_numbers (&head_stack_a, &head_stack_b);
        // print_list(head_stack_a, 'A');

        //print_instructions(NULL);

        /******* Repush to stack A  *****/
        // print_list(head_stack_b, 'B');
        re_push_to_stack_a(&head_stack_a, &head_stack_b);
        if ((head_stack_a) && (head_stack_a)->next && ((head_stack_a)->index > (head_stack_a)->next->index))
            swap_stack(&head_stack_a, 'a');
        print_instructions(NULL);

    }
    // print_list(head_stack_b, 'B');

    // printf("\n\n");
    // print_list(head_stack_a, 'A');
}
