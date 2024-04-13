/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:48:40 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/13 12:30:57 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define DEC "0123456789"
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UPP "0123456789ABCDEF"

typedef unsigned int	t_uint;

size_t	ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(const char *s, int fd);
size_t	ft_putptr_fd(void *ptr, int fd);
size_t	ft_putlbase_fd(long n, char *base, int fd);
size_t	ft_putulbase_fd(size_t n, char *base, int fd);

#endif