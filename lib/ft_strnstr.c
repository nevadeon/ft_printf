/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:05:56 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/06 13:32:50 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big && len)
	{
		i = 0;
		while (little[i] == big[i] && len)
		{
			if (little[i + 1] == '\0')
				return ((char *)big);
			len--;
			i++;
		}
		len = len + i - 1;
		big++;
	}
	return (NULL);
}
