/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:22:39 by ahmez-za          #+#    #+#             */
/*   Updated: 2021/11/17 12:57:33 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if ((*lst) == NULL || del == NULL)
		return ;
	while ((*lst) != NULL)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		(*lst)->next = NULL;
		free(*lst);
		(*lst) = temp;
	}
}
