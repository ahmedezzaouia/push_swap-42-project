/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:10:48 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/13 22:21:54 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct Node {
    int data;
    struct Node* next;
} a_list;

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

void    sa(a_list **head)
{
    a_list *first;   
    a_list *second;   
    first = *head;

    second = first->next;
    first->next = second->next;
    second->next = first;
    *head = second;
}
int main(int ac, char **argv)
{
    int i;
    a_list *head;
    
    i = 0;
    head = NULL;
    int *array = parsing_Input(argv, ac);
    while (i < ac - 1)
    {
        printf("%d\n",array[i]);
        add_node(array[i], &head);
        i++;
    }
    sa(&head);
    a_list *temp;
    temp = head;
    while (temp)
    {
        printf("node = %d\n",temp->data);
        temp = temp->next;
    }
}
