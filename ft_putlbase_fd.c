/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlbase_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:01:57 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/13 12:33:12 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	_recursive(size_t l, char *base, size_t base_len, int fd)
{
	size_t	nb_printed;

	nb_printed = 0;
	if (l >= base_len)
		nb_printed = _recursive(l / base_len, base, base_len, fd);
	ft_putchar_fd(base[l % base_len], fd);
	return (nb_printed + 1);
}

size_t	ft_putlbase_fd(long l, char *base, int fd)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l *= -1;
		return (_recursive((size_t) l, base, base_len, fd) + 1);
	}
	return (_recursive((size_t) l, base, base_len, fd));
}
