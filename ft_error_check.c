/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:39:28 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/08 11:26:16 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_file_extension(const char *filename)
{
    const char  *ext;

    ext = ft_strrchr(filename, '.');
    if (!ext)
        return (0);
    if (ft_strcmp(ext, ".ber") != 0)
        return (0);
    return (1);
}

int check_if_file_exists(const char *filename)
{
    FILE *file;

    file = fopen(filename, "r");
    if (!file)
        return (0);
    fclose(file);
    return (1);
}

int is_rectangular(char **map)
{
    size_t first_line_len;
    size_t i;

    if (!map || !map[0])
        return (0);
    first_line_len = ft_strlen(map[0]);
    i = 1;
    while (map[i])
    {
        if (ft_strlen(map[i]) != first_line_len)
            return (0);
        i++;
    }
    return (1);
}

int check_elements(char **map, t_count *content)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                content->p_count++;
            else if (map[i][j] == 'E')
                content->e_count++;
            else if (map[i][j] == 'C')
                content->c_count++;
            else if (map[i][j] != '1' && map[i][j] != '0')
                return (0);
            j++;
        }
        i++;
    }
    if (content->p_count != 1 || content->e_count != 1 || content->c_count < 1)
        return (0);
    return (1);
}

int check_walls(char **map)
{
    int i;
    int width;
    int height;

    height = 0;
    while (map[height])
        height++;
    width = ft_strlen(map[0]);
    i = 0;
    while (i < width)
    {
        if (map[0][i] != '1' || map[height - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < height)
    {
        if (map[i][0] != '1' || map[i][width - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

