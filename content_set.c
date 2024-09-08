/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:49:19 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/08 13:11:00 by hrasolof         ###   ########.fr       */
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
	data->img.height = 50;
	data->img.width = 50;
	data->img.floor = "img/Grass.xpm";
	data->img.wall = "img/Tree-.xpm";
	data->img.collect = "img/Gem-.xpm";
	data->img.player = "img/Player-.xpm";
	data->img.exit = "img/Portal-.xpm";
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
        ft_printf("Error: One or more images failed to load.\n");
        exit(1);
	}
}

void draw_image_at_position(t_game *data, char map_char, int x, int y)
{
    int img_x;
    int img_y;

    img_x = x * data->img.width;
    img_y = y * data->img.height;
    if (map_char == '1')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_wall, img_x, img_y);
    else if (map_char == 'P')
    {
        data->pos.x = x;
        data->pos.y = y;
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player, img_x, img_y);
    }
    else if (map_char == 'C')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_collect, img_x, img_y);
    else if (map_char == 'E')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_exit, img_x, img_y);
    else
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_floor, img_x, img_y);
}

void render_map(t_game *data)
{
    int x;
    int y;

    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            draw_image_at_position(data, data->map[y][x], x, y);
            x++;
        }
        y++;
    }
}

void cleanup(t_game *data)
{
    int i;
    
    if (data->map)
    {
        i = 0;
        while (data->map[i])
            free(data->map[i++]);
        free(data->map);
    }
    if (data->img.img_floor)
        mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
    if (data->img.img_wall)
        mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
    if (data->img.img_collect)
        mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
    if (data->img.img_player)
        mlx_destroy_image(data->mlx_ptr, data->img.img_player);
    if (data->img.img_exit)
        mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
    if (data->win_ptr)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    if (data->mlx_ptr)
        mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
}
