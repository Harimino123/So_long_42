/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:28:20 by hrasolof          #+#    #+#             */
/*   Updated: 2024/03/13 12:55:02 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*function)(unsigned int, char))
{
	size_t	i;
	char	*p;

	p = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (str[i])
	{
		p[i] = (*function)(i, str[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
