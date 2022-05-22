/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:06:18 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/22 14:25:07 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		sign;
	int		k;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[0] == '\0')
		print_error();
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	k = i;
	while (str[k])
	{
		if (str[k] < '0' || str[k] > '9')
			print_error();
		k++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	if (nb > 2147483647 || nb < -2147483648)
		print_error();
	return (nb);
}
