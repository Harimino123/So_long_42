/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:47:31 by hrasolof          #+#    #+#             */
/*   Updated: 2024/02/27 09:31:21 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t numBytes)
{
	unsigned char	*char_str1;
	unsigned char	*char_str2;

	if (!str1 && !str2)
		return (NULL);
	char_str1 = (unsigned char *)str1;
	char_str2 = (unsigned char *)str2;
	while (numBytes--)
	{
		*char_str1++ = *char_str2++;
	}
	return (str1);
}
