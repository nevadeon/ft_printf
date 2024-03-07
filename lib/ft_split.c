/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:39:45 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/06 13:32:25 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_count_words(const char *s, char c)
{
	int	nb_words;

	nb_words = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			nb_words++;
		s++;
	}
	return (nb_words);
}

static char	**_free(char **tab, int last)
{
	int	i;

	i = 0;
	while (i <= last)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static char	*_strdup_to_c(const char **s, char c)
{
	char	*cpy;
	int		cpy_len;
	int		i;

	cpy_len = 0;
	while ((*s)[cpy_len] && (*s)[cpy_len] != c)
		cpy_len++;
	cpy = (char *) malloc(sizeof(char) * (cpy_len + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < cpy_len)
	{
		cpy[i] = **s;
		(*s)++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	tab = (char **) malloc(sizeof(char *) * (_count_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			tab[i] = _strdup_to_c(&s, c);
			if (tab[i] == NULL)
				return (_free(tab, i));
			i++;
		}
	}
	tab[i] = (char *) NULL;
	return (tab);
}
