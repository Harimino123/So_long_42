/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:45:44 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/08 10:53:04 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *clean_line(char *line)
{
    char *ptr = line;
    while (*ptr)
    {
        if (*ptr == '\r')
            ft_memmove(ptr, ptr + 1, ft_strlen(ptr)); // Replace '\r' with '\0' or move characters left to remove it
        else
            ptr++;
    }
    return line;
}

char *get_map(int fd)
{
    char *line_map;
    char *map_content;
    char *tmp;
    size_t map_len;
    size_t line_len;

    map_len = 0;
    map_content = ft_strdup("");
    if (!map_content)
        return (NULL);
    while ((line_map = get_next_line(fd)) != NULL)
    {
        line_len = ft_strlen(line_map);
        tmp = ft_strjoin(map_content, line_map);
        free(map_content);
        map_content = tmp;
        if (!map_content)
            return(free(line_map), NULL);
        free(line_map);
    }
    if (map_content == NULL)
        return (NULL);
    return (map_content);
}


char **parse_map(int fd, t_game *data)
{
    char *line;
    char *map_content;
    char *temp;

    map_content = NULL;
    while ((line = get_next_line(fd)) != NULL)
    {
        line = clean_line(line);
        temp = map_content;
        map_content = ft_strjoin(map_content, line);
        free(temp);
        free(line);
        temp = map_content;
        map_content = ft_strjoin(map_content, "\n");
        free(temp);
    }
    if (map_content == NULL)
        return NULL;
    data->map = ft_split(map_content, '\n');
    free(map_content);
    if (!data->map)
        return (NULL);
    return (data->map);
}
