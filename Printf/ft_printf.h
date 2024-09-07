/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hari <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:04:45 by hari              #+#    #+#             */
/*   Updated: 2024/04/08 17:36:35 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
size_t	ft_putstr(char *str);
size_t	ft_strlen(const char *str);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_dec_to_hex(unsigned int nombre, int majuscule);
int		dec_to_hex(unsigned long long int addr, char *dest);
int		adr_to_str(unsigned long long int address, char *str);

#endif
