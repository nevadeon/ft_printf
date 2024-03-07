/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:53:16 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/06 13:32:14 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_recursivite(long l, int fd)
{
	if (l >= 10)
		_recursivite(l / 10, fd);
	ft_putchar_fd(l % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = (long) n;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l = -l;
	}
	_recursivite(l, fd);
}
