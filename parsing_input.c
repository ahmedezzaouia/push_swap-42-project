/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:54:51 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 23:21:24 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_sort(t_list_node *head_stack_a)
{
	while (head_stack_a->next)
	{
		if (head_stack_a->data > (head_stack_a->next)->data)
		{
			return (0);
		}
		head_stack_a = head_stack_a->next;
	}
	return (1);
}

void	check_deplicate(t_list_node *head)
{
	t_list_node	*temp;

	while (head)
	{
		temp = head->next;
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

void	add_node(int data, t_list_node **head)
{
	int			i;
	t_list_node	*new;
	t_list_node	*temp;

	i = 0;
	new = malloc(sizeof(t_list_node));
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

int	*parsing_input(char **argv, int ac, t_list_node **head_a)
{
	int	i;
	int	j;
	int	*init_nums;

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
	i = 0;
	while (i < ac - 1)
		add_node(init_nums[i++], head_a);
	check_deplicate(*head_a);
	if (check_stack_sort(*head_a))
		exit(0);
	return (init_nums);
}
