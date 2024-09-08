/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:32:50 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/08 18:32:50 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int count_collectibles(char **map)
{
    int i = 0;
    int j;
    int collectible_count = 0;

    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                collectible_count++;
            j++;
        }
        i++;
    }
    return collectible_count;
}


char **ft_copy_map(char **map)
{
    int i;
    int height;
    char **copy;

    // Calculate height
    height = 0;
    while (map[height])
        height++;

    // Allocate memory for copy
    copy = malloc(sizeof(char *) * (height + 1));
    if (!copy)
        return NULL;

    // Copy each row
    for (i = 0; i < height; i++)
    {
        copy[i] = strdup(map[i]);
        if (!copy[i])
        {
            // Free previously allocated memory on failure
            while (i > 0)
                free(copy[--i]);
            free(copy);
            return NULL;
        }
    }
    copy[height] = NULL; // Null-terminate the array

    return copy;
}

int find_player_position(char **map, int *x, int *y)
{
    int i = 0;
    while (map[i])
    {
        int j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                *x = j;
                *y = i;
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

int flood_fill(char **map, int x, int y, int max_x, int max_y, int *collectibles_left)
{
    if (x < 0 || y < 0 || x >= max_x || y >= max_y)
        return 0;
    // Check if it's a wall or already visited
    if (map[y][x] == '1' || map[y][x] == 'F')
        return 0;

    // If it's a collectible, decrement the collectibles counter
    if (map[y][x] == 'C')
    {
        (*collectibles_left)--;
        map[y][x] = 'F'; // Mark collectible as visited
    }
    // If it's an exit and all collectibles are collected
    if (map[y][x] == 'E' && *collectibles_left == 0)
    {
        return 1; // Found a valid exit after collecting all items
    }

    // Mark the current position as visited
    if (map[y][x] != 'F')
        map[y][x] = 'F';

    // Recursively check all four directions
    if (flood_fill(map, x + 1, y, max_x, max_y, collectibles_left))
        return 1;
    if (flood_fill(map, x - 1, y, max_x, max_y, collectibles_left))
        return 1;
    if (flood_fill(map, x, y + 1, max_x, max_y, collectibles_left))
        return 1;
    if (flood_fill(map, x, y - 1, max_x, max_y, collectibles_left))
        return 1;

    return 0; // No valid path found
}


// Temporary function to check map validity
int ft_temp(char **map, int start_x, int start_y, int total_collectibles)
{
    char **temp;
    int collectibles_left = total_collectibles; // Initialize with total number of collectibles
    int max_x = ft_width(map);
    int max_y = ft_height(map);

    // Copy the map
    temp = ft_copy_map(map);
    if (!temp)
        return 0;
    if (!flood_fill(temp, start_x, start_y, max_x, max_y, &collectibles_left))
    {
        printf("Error: There is no valid path!\n");
        ft_free_map(temp);
        return 0;
    }

    ft_free_map(temp);
    return 1;
}

