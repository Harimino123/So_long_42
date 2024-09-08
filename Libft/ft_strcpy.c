/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:59:12 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/08 23:59:12 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcpy(char *dest, const char *src)
{
    char *dest_start;

    dest_start = dest;
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
    return (dest_start);
}