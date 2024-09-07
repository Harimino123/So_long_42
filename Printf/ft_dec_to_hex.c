/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:01:40 by hrasolof          #+#    #+#             */
/*   Updated: 2024/04/08 17:33:25 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec_to_hex(unsigned int nombre, int majuscule)
{
	int		reste;
	int		i;
	char	hexa[100];
	int		printed_char;

	i = 0;
	printed_char = 0;
	if (nombre == 0)
		return (ft_putchar('0'));
	while (nombre != 0)
	{
		reste = nombre % 16;
		if (reste < 10)
			hexa[i++] = 48 + reste;
		else if (majuscule)
			hexa[i++] = 55 + reste;
		else
			hexa[i++] = 87 + reste;
		nombre /= 16;
	}
	printed_char = i--;
	while (i >= 0)
		ft_putchar(hexa[i--]);
	return (printed_char);
}
