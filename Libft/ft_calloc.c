/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:51:00 by hrasolof          #+#    #+#             */
/*   Updated: 2024/03/07 08:50:01 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_block, size_t size)
{
	char	*cal;
	size_t	calc;

	calc = n_block * size;
	cal = malloc(calc);
	if (!cal)
		return (0);
	ft_bzero(cal, calc);
	return (cal);
}
