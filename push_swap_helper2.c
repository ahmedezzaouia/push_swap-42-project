/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:23:25 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/21 17:50:45 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		i++;
	}
}

void	print_instructions_helper(char **instruct, char *to_print)
{
	printf("%s\n", to_print);
	*instruct = NULL;
}

void	print_instructions(char *instruct)
{
	static char	*e_intruct = 0;

	if (!e_intruct)
		e_intruct = instruct;
	else if (!instruct)
		printf("%s\n", e_intruct);
	else if ((!ft_strncmp(e_intruct, "sb", 3) && \
	!ft_strncmp(instruct, "sa", 3)) || \
	(!ft_strncmp(e_intruct, "sa", 3) && !ft_strncmp(instruct, "sb", 3)))
		print_instructions_helper(&instruct, "ss");
	else if ((!ft_strncmp(e_intruct, "ra", 3) && \
	!ft_strncmp(instruct, "rb", 3)) || \
	(!ft_strncmp(e_intruct, "rb", 3) && !ft_strncmp(instruct, "ra", 3)))
		print_instructions_helper(&instruct, "rr");
	else if ((!ft_strncmp(e_intruct, "rra", 4) && \
	!ft_strncmp(instruct, "rrb", 4)) || \
	(!ft_strncmp(e_intruct, "rrb", 4) && !ft_strncmp(instruct, "rra", 4)))
		print_instructions_helper(&instruct, "rrr");
	else if (instruct && e_intruct)
		printf("%s\n", e_intruct);
	e_intruct = instruct;
}

int	get_list_size(a_list *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

void	lstadd_front(a_list **head, a_list *new)
{
	if (new)
	{
		new->next = (*head);
		*head = new;
	}
}

void	print_list(a_list *head, char stack)
{
	while (head)
	{
		printf("stack %c = %d index == %d\n", stack, head->data, head->index);
		head = head->next;
	}
}
