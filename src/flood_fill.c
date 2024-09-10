/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:23:19 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/09 14:24:00 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	collectible_count;

	i = 0;
	collectible_count = 0;
	if (!map[i])
		return (0);
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
	return (collectible_count);
}

int	find_player_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_copy_map(char **map)
{
	int		i;
	int		height;
	char	**copy;

	height = 0;
	while (map[height])
		height++;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

int	flood_fill(t_flood_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->max_x || y >= data->max_y)
		return (0);
	if (data->map[y][x] == '1' || data->map[y][x] == 'F')
		return (0);
	if (data->map[y][x] == 'C')
	{
		data->collectibles_left--;
		data->map[y][x] = 'F';
	}
	if (data->map[y][x] == 'E' && data->collectibles_left == 0)
		return (1);
	if (data->map[y][x] != 'F')
		data->map[y][x] = 'F';
	if (flood_fill(data, x + 1, y))
		return (1);
	if (flood_fill(data, x - 1, y))
		return (1);
	if (flood_fill(data, x, y + 1))
		return (1);
	if (flood_fill(data, x, y - 1))
		return (1);
	return (0);
}

int	ft_temp(char **map, int start_x, int start_y, int total_collectibles)
{
	t_flood_data	data;
	char		**temp;

	data.max_x = ft_width(map);
	data.max_y = ft_height(map);
	data.collectibles_left = total_collectibles;
	temp = ft_copy_map(map);
	if (!temp)
		return (0);
	data.map = temp;
	if (!flood_fill(&data, start_x, start_y))
	{
		printf("Error: There is no valid path!\n");
		ft_free_map(temp);
		return (0);
	}
	ft_free_map(temp);
	return (1);
}
