/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:21:54 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/07 14:08:12 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_free_map(t_game *data)
{
	int		i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
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
