/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:43:10 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/11 08:53:37 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_printarg(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar((unsigned char) va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base((long) va_arg(args, int), DEC));
	else if (c == 'u')
		return (ft_putnbr_base((long) va_arg(args, unsigned int), DEC));
	else if (c == 'x')
		return (ft_putnbr_base((long) va_arg(args, unsigned int), HEXA_LOW));
	else if (c == 'X')
		return (ft_putnbr_base((long) va_arg(args, unsigned int), HEXA_UPP));
	else if (c == '%')
		return (ft_putchar('%'));
	ft_putchar('%');
	ft_putchar(c);
	return(2);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		nb_printed;

	nb_printed = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			nb_printed += _printarg(*(format), args);
		}
		else
			nb_printed += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (nb_printed);
}
