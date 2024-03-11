/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:40:24 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/11 12:38:22 by ndavenne         ###   ########.fr       */
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

static int	_recursivite2(size_t l, char *base, size_t base_len, int nb_printed)
{
	if (l >= base_len)
		nb_printed = _recursivite(l / base_len, base, base_len, nb_printed);
	ft_putchar(base[l % base_len]);
	return (nb_printed + 1);
}

int	ft_putul_base(size_t n, char *base)
{
	int		nb_printed;
	size_t	base_size;

	nb_printed = 0;
	base_size = ft_strlen(base);
	return (_recursivite2(n, base, base_size, nb_printed));
}
