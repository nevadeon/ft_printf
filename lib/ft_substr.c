/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:13:40 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/06 13:33:00 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	else if ((s_len - start) < len)
		len = s_len - start;
	output = (char *) malloc(sizeof(char) * len + 1);
	if (output == NULL)
		return ((char *) NULL);
	i = 0;
	while (s[start] && len--)
		output[i++] = s[start++];
	output[i] = '\0';
	return (output);
}
