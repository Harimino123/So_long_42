/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:38:41 by hrasolof          #+#    #+#             */
/*   Updated: 2024/04/08 17:37:26 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_longueur(int n)
{
	int	ln;

	ln = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		ln++;
	}
	return (ln);
}

int	ft_putnbr_u(unsigned int n)
{
	int	len;

	if (n > 9)
	{
		len = ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
		return (len + 1);
	}
	else
		ft_putchar(n + '0');
	return (ft_longueur(n));
}
