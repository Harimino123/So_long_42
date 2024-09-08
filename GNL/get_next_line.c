/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:00:14 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/09 00:02:17 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copy_char(char *str, int index)
{
	char	*new_stock;
	int		j;
	int		k;

	if (contains_newline(str) == 0)
		return (str);
	j = 0;
	k = 0;
	new_stock = malloc((index + 2) * sizeof(char));
	if (!new_stock)
		return (NULL);
	while (j <= index)
		new_stock[k++] = str[j++];
	new_stock[k] = '\0';
	free(str);
	return (new_stock);
}

int	contains_newline(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *buf)
{
	char	*stock;
	int		bytes_reads;
	char	*temp;

	stock = NULL;
	bytes_reads = 0;
	if (buf)
		stock = ft_strdup(buf);
		if (!stock)
            return NULL;
	while (contains_newline(buf) == 0)
	{
		bytes_reads = (int)read(fd, buf, BUFFER_SIZE);
		if (bytes_reads <= 0)
			break ;
		buf[bytes_reads] = '\0';
		temp = ft_strjoin(stock, buf);
		if (!temp)
            return (free(stock), NULL);
		free(stock);
        stock = temp;
	}
	if (bytes_reads <= 0 && !stock[0])
		return (free(stock), NULL);
	return (stock);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*stock;
	static char		buf[BUFFER_SIZE + 1];
	int				newline_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = read_line(fd, buf);
	line = NULL;
	if (!stock)
		return (free(stock), NULL);
	buf[0] = '\0';
	newline_index = index_of_newline(stock);
	if (newline_index >= 0)
		ft_strcpy1(buf, &stock[newline_index + 1]);
	line = copy_char(stock, index_of_newline(stock));
	return (line);
}
