/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:40:24 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/13 11:19:32 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	_recursive1(long l, char *base, int base_len, int fd)
{
	size_t	nbp;

	nbp = 0;
	if (l >= base_len)
		nbp += _recursive1(l / base_len, base, base_len, fd);
	ft_putchar_fd(base[l % base_len], fd);
	return (nbp + 1);
}

size_t	ft_putlbase_fd(long n, char *base, int fd)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		return (_recursive1(n, base, base_len, fd) + 1);
	}
	return (_recursive1(n, base, base_len, fd));
}

static size_t	_recursive2(size_t l, char *base, size_t base_len, int fd)
{
	size_t	nbp;

	nbp = 0;
	if (l >= base_len)
		nbp += _recursive2(l / base_len, base, base_len, fd);
	ft_putchar_fd(base[l % base_len], fd);
	return (nbp + 1);
}

size_t	ft_putulbase_fd(size_t n, char *base, int fd)
{
	size_t	nb_printed;
	size_t	base_len;

	nb_printed = 0;
	base_len = ft_strlen(base);
	return (_recursive2(n, base, base_len, fd));
}
