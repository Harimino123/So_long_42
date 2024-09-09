/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:45:44 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/09 00:42:30 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char *clean_line(char *line)
{
    char *ptr;

    ptr = line;
    while (*ptr)
    {
        if (*ptr == '\r')
            ft_memmove(ptr, ptr + 1, ft_strlen(ptr)); // Replace '\r' with '\0' or move characters left to remove it
        else
            ptr++;
    }
    return (line);
}

char *read_and_concat_lines(int fd)
{
    char *line_map;
    char *map_content;
    char *tmp;
    int    line_c;

    map_content = ft_strdup("");
    if (!map_content)
        return (NULL);
    line_c = 0;
    while ((line_map = get_next_line(fd)) != NULL)
    {
        line_c++;
        tmp = ft_strjoin(map_content, line_map);
        free(map_content);
        map_content = tmp;
        if (!map_content)
        {
            free(line_map);
            return (NULL);
        }
        free(line_map);
    }
    if (line_c == 0)
    {
        free(map_content);
        return (NULL);
    }
    return (map_content);
}

char *get_map(int fd)
{
    char *map_content;

    map_content = read_and_concat_lines(fd);
    if (map_content == NULL || *map_content == '\0')
    {
        ft_printf("Error : Map is empty or invalid\n");
        free(map_content);
        return (NULL);
    }
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
        return (NULL);
    data->map = ft_split(map_content, '\n');
    free(map_content);
    if (!data->map)
        return (NULL);
    return (data->map);
}
