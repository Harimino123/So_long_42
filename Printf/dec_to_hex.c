/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:33:11 by hrasolof          #+#    #+#             */
/*   Updated: 2024/04/08 17:38:33 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dec_to_hex(unsigned long long int addr, char *dest)
{
	int	i;
	int	reste;
	int	printed_char;

	i = 0;
	printed_char = 0;
	while (addr != 0)
	{
		reste = addr % 16;
		if (reste < 10)
			dest[i++] = 48 + reste;
		else
			dest[i++] = 87 + reste;
		addr /= 16;
		printed_char++;
	}
	return (printed_char);
}
