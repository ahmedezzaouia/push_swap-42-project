/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:31:36 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/22 21:22:54 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_actions(char *line, t_list_node **stack_a, t_list_node **stack_b)
{
	if (!ft_strncmp("sa\n", line, 4))
		swap_stack(stack_a, 0);
	else if (!ft_strncmp("sb\n", line, 4))
        swap_stack(stack_b, 0);
    else if (!ft_strncmp("pa\n", line, 4))
        push_stack(stack_b, stack_a, 0);
    else if (!ft_strncmp("pb\n", line, 4))
        push_stack(stack_a, stack_b, 0);
    else if (!ft_strncmp("ra\n", line, 4))
        rotat_stack(stack_a, 0);
    else if (!ft_strncmp("rb\n", line, 4))
        rotat_stack(stack_b, 0);
    else if (!ft_strncmp("rra\n", line, 4))
        reverse_stack(stack_a, 0);
    else if (!ft_strncmp("rrb\n", line, 4))
        reverse_stack(stack_b, 0);
    else if (!ft_strncmp("ss\n", line, 4))
    {
        swap_stack(stack_a, 0);
        swap_stack(stack_b, 0);
    }
    else if (!ft_strncmp("rr\n", line, 4))
    {
        rotat_stack(stack_a, 0);
        rotat_stack(stack_b, 0);
    }
    else if (!ft_strncmp("rrr\n", line, 4))
    {
        reverse_stack(stack_a, 0);
        reverse_stack(stack_b, 0);
    }
    else
    {
        ft_printf("Error\n");
        exit (1);
    }
}

int main(int ac, char **argv)
{
    char *line;
    t_list_node *stack_a;
    t_list_node *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (ac == 1)
        exit(0);
    parsing_input(argv, ac, &stack_a);
    line = get_next_line(0);
    while (line)
    {
        do_actions(line, &stack_a, &stack_b);
        free(line);
        line = get_next_line(0);
    }
    // free(line);

    // t_list_node *temp;
    // while (temp)
    // {
    //     /* code */
    //     ft_printf("stack data == [%d]\n", temp->data);
    //     temp = temp->next;
    // }
    if (check_stack_sort(stack_a) == 1)
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
}