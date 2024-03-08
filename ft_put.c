/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:44:00 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/08 15:59:15 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], sizeof(char));
		i++;
	}
	return (i);
}

int	ft_putptr(void *ptr)
{
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_putnbr_base((long) ptr, HEXA_LOW) + 2);
}

static int	_recursivite(long l, char *base, int base_size, int nb_printed)
{
	if (l >= base_size)
		nb_printed = _recursivite(l / base_size, base, base_size, nb_printed);
	ft_putchar(base[l % base_size]);
	return (nb_printed + 1);
}

int	ft_putnbr_base(long n, char *base)
{
	int	nb_printed;
	int	base_size;

	nb_printed = 0;
	base_size = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-');
		nb_printed++;
		n = -n;
	}
	return (_recursivite(n, base, base_size, nb_printed));
}
