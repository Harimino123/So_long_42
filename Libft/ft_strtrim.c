/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:02:35 by hrasolof          #+#    #+#             */
/*   Updated: 2024/03/12 11:53:29 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;
	int	len;

	len = ft_strlen(s1);
	if (!set || !s1)
		return (0);
	start = 0;
	while (ft_strchr((char *)set, s1[start]))
		start++;
	end = len - 1;
	while (ft_strrchr((char *)set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
