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
    if (keycode == 65307)
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

