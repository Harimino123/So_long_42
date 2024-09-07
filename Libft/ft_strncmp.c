/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:33:39 by hrasolof          #+#    #+#             */
/*   Updated: 2024/02/29 08:37:14 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (i < (n - 1) && str1[i] == str2[i]
		&& str1[i] != '\0' && str2[i] != '\0')
	{
		i++;
	}
	return ((int)((unsigned char)str1[i] - (unsigned char)str2[i]));
}
