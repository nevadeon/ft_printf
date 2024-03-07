/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:06:26 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/05 20:11:01 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	if ((unsigned char) c == '\0')
		return ((char *)(s + ft_strlen(s)));
	ptr = NULL;
	while (*s)
	{
		if ((unsigned char) *s == (unsigned char) c)
			ptr = (char *) s;
		s++;
	}
	return (ptr);
}
