/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:08:06 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/05/22 21:11:40 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_get_remaining(char *save)
{
	int		i;
	char	*remain;

	i = 0;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	remain = ft_substr(save, i, ft_strlen(save));
	free(save);
	return (remain);
}

char	*free_buffer(char *buffer)
{
	free(buffer);
	return (NULL);
}

void	ft_strcat(char *s1, char *s2)
{
	int	i;
	int	len;

	i = 0;
	if (!s1 && !s2)
		return ;
	len = ft_strlen(s1);
	while (s2[i])
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = '\0';
}

char	*ft_str_join(const char *s1, const char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	i = 0;
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	str = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!str)
		return (0);
	ft_strcat(str, (char *)s1);
	ft_strcat(str, (char *)s2);
	free((char *)s1);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*save = NULL;
	int			r;

	buffer = NULL;
	line = NULL;
	r = 1;
	if (fd < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (ft_is_new_line(save) != 1 && r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
			return (free_buffer(buffer));
		buffer[r] = '\0';
		save = ft_str_join(save, buffer);
	}
	free(buffer);
	line = ft_get_line(save);
	save = ft_get_remaining(save);
	return (line);
}
