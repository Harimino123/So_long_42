/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:21:54 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/08 12:18:54 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_exit(t_game *data)
{
    cleanup(data);
    exit(0);
}

void ft_free_map(char **map)
{
    int i = 0;

    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int ft_height(char **map)
{
    int h;

    h = 0;
    while(map[h])
        h++;
    return (h);
}

int ft_width(char **map)
{
    int w;

    w = ft_strlen(map[0]);
    return (w);
}

int ft_free(char **str)
{
    int i = 0;

    while (str[i])
        free(str[i++]);
    free(str);
    return (0);
}

