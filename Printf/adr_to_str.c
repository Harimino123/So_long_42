/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adr_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:30:24 by hrasolof          #+#    #+#             */
/*   Updated: 2024/04/08 17:39:35 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	adr_to_str(unsigned long long int address, char *str)
{
	char	hexa[100];
	int		printed_char;
	int		k;
	int		j;

	printed_char = 0;
	if (address == 0)
		return (ft_putstr("(nil)"));
	k = 0;
	write(1, "0x", 2);
	printed_char = dec_to_hex(address, hexa);
	j = printed_char - 1;
	while (j >= 0)
		str[k++] = hexa[j--];
	str[k] = '\0';
	ft_putstr(str);
	return (printed_char + 2);
}
