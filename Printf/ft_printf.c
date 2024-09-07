/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:52:47 by hrasolof          #+#    #+#             */
/*   Updated: 2024/04/08 17:43:25 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_spec(char c, va_list args, size_t *printed_char)
{
	int		majuscule;
	char	addr[20];

	if (c == 'c')
		*printed_char += ft_putchar(va_arg(args, int));
	else if (c == 's')
		*printed_char += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		*printed_char += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		*printed_char += ft_putnbr_u(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
	{
		majuscule = (c == 'X');
		*printed_char += ft_dec_to_hex(va_arg(args, unsigned int), majuscule);
	}
	else if (c == 'p')
		*printed_char += adr_to_str(va_arg(args, unsigned long int), addr);
	else if (c == '%')
		*printed_char += ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	printed_char;
	size_t	i;

	printed_char = 0;
	i = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			format_spec(format[i + 1], args, &printed_char);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			printed_char++;
		}
		i++;
	}
	va_end(args);
	return ((int)printed_char);
}
