/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:45:08 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/10 12:08:48 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_ec(t_ff_data *data, int x, int y)
{
	if (data->map[y][x] == 'E')
	{
		if (data->collectibles_left == 0)
			return (1);
		else
			return (0);
	}
	return (-1);
}
