/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:01:31 by hrasolof          #+#    #+#             */
/*   Updated: 2024/03/12 12:21:01 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*function)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (str[i])
	{
		function(i, &str[i]);
		i++;
	}
}
