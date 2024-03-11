/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putothers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:44:00 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/11 11:47:38 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], sizeof(char));
		i++;
	}
	return (i);
}

int	ft_putptr(void *p)
{
	if (p == NULL)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_putul_base((size_t) p, HEXA_LOW) + 2);
}
