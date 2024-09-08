/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:48:29 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/08 22:29:03 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
        ft_printf("Error: Map is not rectangular.\n");
        return (0);
    }
    if (!check_elements(map, content))
    {
        ft_printf("Error: Map contains invalid elements or incorrect number of elements.\n");
        return (0);
    }
    if (!check_walls(map))
    {
        ft_printf("Error: Map is not surrounded by walls.\n");
        return (0);
    }
    return (1);
}

static void *st_free(char **str)
{
    int i = 0;

    while (str[i])
        free(str[i++]);
    free(str);
    return (NULL);
}

void *validate_and_init_map(t_game *data, int total_collectibles)
{
    if (!data->map)
    {
        ft_printf("Error parsing map.\n");
        return (NULL);
        }
    if (!data->map)
        return (ft_printf("Error parsing map.\n"), NULL);
    if (!validate_map(data->map, &(data->content)))
        return (st_free(data->map), NULL);
    if (!find_player_position(data->map, &data->pos.x, &data->pos.y))
        return (st_free(data->map), NULL);
    if (!ft_temp(data->map, data->pos.x, data->pos.y, total_collectibles))
        return (st_free(data->map), NULL);
}

char **load_map(char **str, t_game *data)
{
    int     fd;
    int total_collectibles = 0;

    fd = 0;
    data->map = NULL;
    if (check_file_extension(str[1]) == 0)
    {
        ft_printf("Invalid map file extension. Expected .ber\n");
        return (NULL);
    }
    fd = open(str[1], O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Failed to open file: %s\n", str[1]);
        return (NULL);
    }
    data->map= parse_map(fd, data);
    close (fd);
    total_collectibles = count_collectibles(data->map);
    validate_and_init_map(data, total_collectibles);
    return (data->map);
}
