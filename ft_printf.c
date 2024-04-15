/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:43:10 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/15 15:59:45 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	_printarg(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd((unsigned char) va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_putptr_fd(va_arg(args, void *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putlbase_fd((long) va_arg(args, int), DEC, 1));
	else if (c == 'u')
		return (ft_putulbase_fd((size_t) va_arg(args, t_uint), DEC, 1));
	else if (c == 'x')
		return (ft_putulbase_fd((size_t) va_arg(args, t_uint), HEXA_LOW, 1));
	else if (c == 'X')
		return (ft_putulbase_fd((size_t) va_arg(args, t_uint), HEXA_UPP, 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (ft_printf("%%%c", c));
}

size_t	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	nb_printed;

	nb_printed = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
			nb_printed += _printarg(*(++format), args);
		else
			nb_printed += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (nb_printed);
}
