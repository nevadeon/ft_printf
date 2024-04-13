/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:24:32 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/13 12:27:05 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	if (s == NULL)
		return (ft_putstr_fd("(null)", 1));
	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}
