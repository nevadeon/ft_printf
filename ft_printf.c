/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:43:10 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/08 15:57:07 by ndavenne         ###   ########.fr       */
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
	return (0);
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

#include <assert.h>

int	main(void)
{
	int *ptr;

	assert(printf("") == ft_printf(""));
	assert(printf("Hello world!\n") == ft_printf("Hello world!\n"));
	assert(printf("%char\n", 'c') == ft_printf("%char\n", 'c'));
	assert(printf("%s", "string\n") == ft_printf("%s", "string\n"));
	assert(printf("%p pointer\n", ptr) == ft_printf("%p pointer\n", ptr));
	assert(printf("%d school\n", 42) == ft_printf("%d school\n", 42));
	assert(printf("%i is a great number\n", 69) == ft_printf("%i is a great number\n", 69));
	assert(printf("%u\n", 4354538) == ft_printf("%u\n", 4354538));
	assert(printf("%x\n", 4354538) == ft_printf("%x\n", 4354538));
	assert(printf("%X\n", 4354538) == ft_printf("%X\n", 4354538));
	assert(printf("%%%%%%%%\n") == ft_printf("%%%%%%%%\n"));

	return (0);
}
