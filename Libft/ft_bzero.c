/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:51:53 by hrasolof          #+#    #+#             */
/*   Updated: 2024/03/07 08:49:22 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

void	ft_bzero(void *buff, size_t len)
{
	unsigned char	*i;

	i = buff;
	while (len--)
	{
		*i++ = 0;
	}
}
