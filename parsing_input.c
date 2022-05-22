/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:54:51 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/22 02:46:19 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_stack_sort(t_list_node *head_stack_a)
// {
// 	while (head_stack_a->next)
// 	{
// 		if (head_stack_a->data > (head_stack_a->next)->data)
// 		{
// 			return (0);
// 		}
// 		head_stack_a = head_stack_a->next;
// 	}
// 	return (1);
// }

// void	check_deplicate(t_list_node *head)
// {
// 	t_list_node	*temp;

// 	while (head)
// 	{
// 		temp = head->next;
// 		while (temp)
// 		{
// 			if (head->data == temp->data)
// 			{
// 				printf("Error\n");
// 				exit(1);
// 			}
// 			temp = temp->next;
// 		}
// 		head = head->next;
// 	}
// }

// void	add_node(int data, t_list_node **head)
// {
// 	int			i;
// 	t_list_node	*new;
// 	t_list_node	*temp;

// 	i = 0;
// 	new = malloc(sizeof(t_list_node));
// 	if (!new)
// 		return ;
// 	new->data = data;
// 	new->next = NULL;
// 	if (*head == NULL)
// 		*head = new;
// 	else
// 	{
// 		temp = *head;
// 		while (temp->next)
// 		{
// 			temp = temp->next;
// 		}
// 		temp->next = new;
// 	}
// }

// int	*parsing_input(char **argv, int ac, t_list_node **head_a)
// {
// 	int	i;
// 	int	j;
// 	int	*init_nums;

// 	i = 1;
// 	j = 0;
// 	init_nums = malloc(sizeof(int) * ac);
// 	if (!init_nums)
// 		return (NULL);
// 	while (argv[i])
// 	{
// 		init_nums[j] = ft_atoi(argv[i]);
// 		i++;
// 		j++;
// 	}
// 	i = 0;
// 	while (i < ac - 1)
// 		add_node(init_nums[i++], head_a);
// 	check_deplicate(*head_a);
// 	if (check_stack_sort(*head_a))
// 		exit(0);
// 	return (init_nums);
// }


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
				// ft_printf("Error\n");
				write (2, "Error\n", 6);
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

// int	*parsing_input(char **argv, int ac, t_list_node **head_a)
// {
// 	int	i;
// 	int	j;
// 	int	*init_nums;
// 	char **str;
// 	int	k;

// 	i = 1;
// 	j = 0;
// 	k = 0;
// 	init_nums = malloc(sizeof(int) * ac);
// 	if (!init_nums)
// 		return (NULL);
// 	while (argv[i])
// 	{
// 		str = ft_split(argv[i], ' ');
// 		k = 0;
// 		while (str[k] != 0)
// 		{
// 			init_nums[j] = ft_atoi(str[k]);
// 			// ft_printf("initR == [%d]\n",init_nums[j]);
// 			j++;
// 			k++;
// 		}
// 		i++;
// 	}
// 	k = 0;
// 	while (k < j)
// 		add_node(init_nums[k++], head_a);
// 	check_deplicate(*head_a);
// 	if (check_stack_sort(*head_a))
// 		exit(0);
// 	return (init_nums);
// }

char *joiner(char **av)
{
	int i;
	char *s;
	char *tmp;

	i = 1;
	s = ft_strdup("");
	while(av[i])
	{
		tmp = s;
		s = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	// printf("s == [%s]\n",s);
	return (s);
}

int two_d_len(char **s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

int	*parsing_input(char **argv, int ac, t_list_node **head_a)
{
	int	i;
	int len;
	char *s;
	char **str;
	int *n;
	i = 0;
	
	if (ac >= 2)
		s = joiner(argv);
	str = ft_split(s, ' ');	
	len = two_d_len(str);
	n = malloc((sizeof(int) * len));
	while(i < len )
	{
		n[i] = ft_atoi(str[i]);
		i++;
	}
	i = 0;
	while (i < len)
		add_node(n[i++], head_a);
	check_deplicate(*head_a);
	return (n);
}