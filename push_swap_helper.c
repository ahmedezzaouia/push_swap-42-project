/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:22:00 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/19 14:00:30 by ahmez-za         ###   ########.fr       */
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


void	print_instructions(char *instruct)
{
	static char *e_intruct = 0;
	// printf("instruct = [%s]\n",instruct);

	if (!e_intruct)
	{
		e_intruct = instruct;
	// printf("e_intruct = [%s]\n",e_intruct);
	}
	else if (!instruct)
	{
		printf("%s\n",e_intruct);
	}
	else if ((!ft_strncmp(e_intruct, "sb", 3) && !ft_strncmp(instruct, "sa", 3)) || \
	 	(!ft_strncmp(e_intruct, "sa", 3) && !ft_strncmp(instruct, "sb", 3)))
	{
		printf("ss\n");
		instruct = NULL;
	}
	else if ((!ft_strncmp(e_intruct, "ra", 3) && !ft_strncmp(instruct, "rb", 3)) || \
	 	(!ft_strncmp(e_intruct, "rb", 3) && !ft_strncmp(instruct, "ra", 3)))
	{
		// printf("hey");
		printf("rr\n");
		instruct = NULL;

	}
	else if ((!ft_strncmp(e_intruct, "rra", 4) && !ft_strncmp(instruct, "rrb", 4)) || \
	 	(!ft_strncmp(e_intruct, "rrb", 4) && !ft_strncmp(instruct, "rra", 4)))
	{
		printf("rrr\n");
		instruct = NULL;

	}
	// the two value is not equal then print them 
	else if (instruct && e_intruct)
	{
		printf("%s\n",e_intruct);
		// printf("%s\n",instruct);
		// instruct = NULL;

	}
	e_intruct = instruct;
	// printf("last e_intruct = [%s]\n",e_intruct);

}


int position(a_list *a, int size, int min, int max)
{
    int i;
    int pos;

    i = 1;
    pos = -1;
    while (a)
    {
        if (a->index >= min && a->index <= max)
        {
            pos = i;
            if (pos <= (size / 2))
                return (pos);
        }
        i++;
		a = a->next;
    }
    return (pos);
}