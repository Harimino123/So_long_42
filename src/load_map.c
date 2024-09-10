/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:48:29 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/10 13:44:18 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	validate_map(char **map, t_count *content)
{
	if (!is_rectangular(map))
	{
		ft_printerror("Error\nMap is not rectangular.\n");
		return (0);
	}
	if (!check_elements(map, content))
	{
		ft_printerror("Error\nMap contains invalid elements");
		ft_printerror(" or incorrect number of elements.\n");
		return (0);
	}
	if (!check_walls(map))
	{
		ft_printerror("Error\nMap is not surrounded by walls.\n");
		return (0);
	}
	return (1);
}

static int	st_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

int	validate_and_init_map(t_game *data, int total_collectibles)
{
	if (!data->map || !data->map[0])
	{
		ft_printerror("Error\nParsing map failed || Map invalid or empty.\n");
		ft_free(data->map);
		return (0);
	}
	if (!validate_map(data->map, &(data->content))
		|| !find_player_position(data->map, &data->pos.x, &data->pos.y)
		|| !ft_temp(data->map, data->pos.x, data->pos.y, total_collectibles))
		return (st_free(data->map));
	return (1);
}

char	**load_map(char **str, t_game *data)
{
	int	fd;
	int	total_collectibles;

	total_collectibles = 0;
	fd = 0;
	data->map = NULL;
	if (!check_file_extension(str[1]))
	{
		ft_printerror("Error\nInvalid map. Expected <filename>.ber\n");
		return (NULL);
	}
	fd = open(str[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printerror("Error\nFile doesn't exist or wrong path\n");
		return (NULL);
	}
	data->map = parse_map(fd, data);
	close(fd);
	if (data->map != NULL)
		total_collectibles = count_collectibles(data->map);
	if (validate_and_init_map(data, total_collectibles) == 0)
		return (0);
	return (data->map);
}
