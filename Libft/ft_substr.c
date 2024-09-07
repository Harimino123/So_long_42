/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:31:43 by hrasolof          #+#    #+#             */
/*   Updated: 2024/03/11 08:32:21 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!str)
		return (0);
	if (ft_strlen(str) < start)
		len = 0;
	if (ft_strlen(str) - start < len)
		len = ft_strlen(str + start);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i >= start && j < len)
			p[j++] = str[i];
		i++;
	}
	p[j] = '\0';
	return (p);
}
