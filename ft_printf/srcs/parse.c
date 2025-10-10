/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 09/10/2025 16:36:51 by fducrot           #+#    #+#             */
/*   Updated: 10/10/2025 08:33:08 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_format(va_list arg, char format, int len)
{
	if (format == 's')
		len += ft_putstr_pf(va_arg(arg, char *));
	else if (format == 'c')
		len += ft_putchar_pf(va_arg(arg, int));
	else if (format == 'p')
		len += ft_putvoid_pf((unsigned long long)va_arg(arg, void *),
				"0123456789abcdef");
	else if (format == 'd' || format == 'i')
		len += ft_putnumb_int_pf(va_arg(arg, int));
	else if (format == 'u')
		len += ft_putnumb_unsingd_pf(va_arg(arg, unsigned int));
	else if (format == 'x')
		len += ft_putnumb_hexa_pf(va_arg(arg, unsigned int),
				"0123456789abcdef");
	else if (format == 'X')
		len += ft_putnumb_hexa_pf(va_arg(arg, unsigned int),
				"0123456789ABCDEF");
	else if (format == '%')
	{
		ft_putchar_pf('%');
		len += 1;
	}
	return (len);
}
