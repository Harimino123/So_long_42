/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:14:33 by hrasolof          #+#    #+#             */
/*   Updated: 2024/08/22 12:51:20 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_game  data;
    if (ac != 2)
    {
        printf("Usage %s <path/map_file.ber>\n", av[0]);
        return (1);
    }
    data.count = 0;
    data.mlx_ptr = mlx_init();
    content_set(&(data.content));
    data.map = load_map(av, &data);
    if (data.map)
    {
        printf("Map valid.\n");
        return (1);
    }
}

/* test*/
