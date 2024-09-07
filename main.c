/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:14:33 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/07 14:15:21 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_key(int keycode, t_game *data)
{
    if (keycode == W_KEY)
        move_player(data, 0, -1);
    else if (keycode == A_KEY)
        move_player(data, -1, 0);
    else if (keycode == S_KEY)
        move_player(data, 0, 1);
    else if (keycode == D_KEY)
        move_player(data, 1, 0);
    else if (keycode == ESC_KEY)
    {
        cleanup(data);
        exit(0);
    }
    return (0);
}

int handle_exit(t_game *data)
{
    cleanup(data);
    exit(0);
}

void ft_set_pos(t_game *data, int new_x, int new_y)
{
    data->map[data->pos.y][data->pos.x] = '0'; // Set old position to floor
    data->map[new_y][new_x] = 'P';  // Set new position to player
    data->pos.x = new_x;
    data->pos.y = new_y;
}


void move_player(t_game *data, int x_offset, int y_offset)
{
    int new_x = data->pos.x + x_offset;
    int new_y = data->pos.y + y_offset;
    if (data->map[new_y][new_x] == '1')
        return ;
    if (data->map[new_y][new_x] == 'C')
    {
        data->content.c_count--;
        data->map[new_y][new_x] = '0';
    }

    if (data->map[new_y][new_x] == 'E')
    {
        if (data->content.c_count == 0)
        {
            printf("You Win!\n");
            handle_exit(data);
        }
        return ;
    }
    ft_set_pos(data, new_x, new_y);
    data->count++;
    ft_printf("Moves: %d\n", data->count);
    render_map(data);
}



int main(int ac, char **av)
{
    t_game  data;

    if (ac != 2)
    {
        ft_printf("Usage %s <path/map_file.ber>\n", av[0]);
        return (1);
    }
    data.count = 0;
    data.mlx_ptr = mlx_init();
    content_set(&(data.content));
    data.map = load_map(av, &data);
    if (data.map == NULL)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, ft_width(data.map) * 50, ft_height(data.map) * 50, "So_long");
    set_img(&data);
    render_map(&data);
    mlx_key_hook(data.win_ptr, handle_key, &data);
    mlx_hook(data.win_ptr, 17, 0, handle_exit, &data);
    mlx_loop(data.mlx_ptr);
    cleanup(&data);
}

