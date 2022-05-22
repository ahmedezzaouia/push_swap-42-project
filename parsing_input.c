/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:54:51 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/22 21:16:57 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*joiner(char **av)
{
	int		i;
	char	*s;
	char	*tmp;

	i = 1;
	s = ft_strdup("");
	while (av[i])
	{
		if (!*av[i])
			print_error();
		tmp = s;
		s = ft_strjoin(tmp, av[i]);
		i++;
	}
	return (s);
}

int	two_d_len(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	*parsing_input(char **argv, int ac, t_list_node **head_a)
{
	int		i;
	int		*n;
	int		len;
	char	*s;
	char	**str;

	i = 0;
	if (ac >= 2)
		s = joiner(argv);
	str = ft_split(s, ' ');
	len = two_d_len(str);
	n = malloc((sizeof(int) * len));
	while (i < len)
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
