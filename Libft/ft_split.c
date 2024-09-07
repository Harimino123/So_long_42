/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:17:22 by hrasolof          #+#    #+#             */
/*   Updated: 2024/03/13 13:14:36 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_w(const char *s1, char sep)
{
	size_t	len;

	if (!*s1)
		return (0);
	len = 0;
	while (*s1)
	{
		while (*s1 == sep)
			s1++;
		if (*s1)
			len++;
		while (*s1 != sep && *s1)
			s1++;
	}
	return (len);
}

char	**ft_split(char const *str, char separator)
{
	size_t	i;
	size_t	j;
	char	**p;
	size_t	w_len;

	p = malloc(sizeof(char *) * (count_w(str, separator) + 1));
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == separator)
			i++;
		w_len = 0;
		while (str[i + w_len] && str[i + w_len] != separator)
			w_len++;
		if (w_len > 0)
		{
			p[j++] = ft_substr(str, i, w_len);
			i += w_len;
		}
	}
	p[j] = (NULL);
	return (p);
}
