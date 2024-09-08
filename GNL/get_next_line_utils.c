/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:12:16 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/08 22:25:58 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../so_long.h"

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char *ft_strjoin(const char *dest, const char *src)
{
    char *result;
    size_t dest_len;
    size_t src_len;
    size_t total_len;
    size_t i;

    if (!dest && !src)
        return (NULL);
    if (!dest)
        return (ft_strdup(src));
    if (!src)
        return (ft_strdup(dest));
    total_len = (dest_len = ft_strlen(dest)) + (src_len = ft_strlen(src));
    result = (char *)malloc(total_len + 1);
    if (!result)
        return NULL;
    i = 0;
    while (i < dest_len)
	{
        result[i] = dest[i];
		i++;
	}
    i = 0;
    while (i < src_len)
	{
        result[dest_len + i] = src[i];
		i++;
	}
    result[total_len] = '\0';
    return result;
}

char	*ft_strdup(const char *src)
{
	char	*p;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	index_of_newline(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
