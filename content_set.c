/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:49:19 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/02 20:49:19 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void content_set(t_count *content)
{
    content->exit = 'E';
    content->collectible = 'C';
    content->player = 'P';
    content->wall = '1';
    content->space = '0';
    content->p_count = 0;
    content->e_count = 0;
    content->c_count = 0;
}

void	set_img(t_game *data)
{
	data->img.height = 80;
	data->img.width = 80;
	data->img.floor = ""; //set path
	data->img.wall = ""; //set path
	data->img.collect = ""; //set path
	data->img.player = ""; //set path
	data->img.exit = ""; //set path
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
			&(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	if (!data->img.img_wall || !data->img.img_floor || !data->img.img_exit ||
        !data->img.img_collect || !data->img.img_player)
	{
        printf("Error: One or more images failed to load.\n");
        exit(1);
	}
}

// void	*ft_free_map(t_game *data)
// {
// 	int		i;

// 	i = 0;
// 	while (data->map[i] != NULL)
// 	{
// 		free(data->map[i]);
// 		i++;
// 	}
// 	free(data->map);
// 	data->map = NULL;
// 	return (0);
// }