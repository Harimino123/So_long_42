/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:48:29 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/07 13:53:53 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int validate_map(char **map, t_count *content)
{
    int width;
    int height;

    height = 0;
    while (map[height])
        height++;
    width = ft_strlen(map[0]);

    if (!is_rectangular(map))
    {
        printf("Error: Map is not rectangular.\n");
        return (0);
    }
    if (!check_elements(map, content))
    {
        printf("Error: Map contains invalid elements or incorrect number of elements.\n");
        return (0);
    }
    if (!check_walls(map))
    {
        printf("Error: Map is not surrounded by walls.\n");
        return (0);
    }
    return (1);
}

char **load_map(char **str, t_game *data)
{
    int     fd;

    fd = 0;
    data->map = NULL;
    if (!check_file_extension(str[1]))
        return (printf("Invalid map file extension. Expected .ber\n"), NULL);
    fd = open(str[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Failed to open file: %s\n", str[1]);
        return (NULL);
    }
    data->map = parse_map(fd, data);
    close(fd);
    if (!data->map)
        return (printf("Error parsing map.\n"), NULL);
    if (!validate_map(data->map, &data->content))
        return (NULL);
    return (data->map);
}

