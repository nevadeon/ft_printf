/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulbase_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:02:52 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/13 12:31:14 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	_recursive(size_t ul, char *base, size_t base_len, int fd)
{
	size_t	nb_printed;

	nb_printed = 0;
	if (ul >= base_len)
		nb_printed += _recursive(ul / base_len, base, base_len, fd);
	ft_putchar_fd(base[ul % base_len], fd);
	return (nb_printed + 1);
}

size_t	ft_putulbase_fd(size_t ul, char *base, int fd)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	return (_recursive(ul, base, base_len, fd));
}
