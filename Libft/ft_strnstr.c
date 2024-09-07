/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:10:50 by hrasolof          #+#    #+#             */
/*   Updated: 2024/03/02 14:33:37 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	if ((big == NULL || little == NULL) && !n)
		return (0);
	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < n)
	{
		j = 0;
		while (big[i + j] != '\0'
			&& little[j] != '\0'
			&& big[i + j] == little[j]
			&& i + j < n)
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
