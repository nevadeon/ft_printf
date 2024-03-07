/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:33:44 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/06 13:31:55 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = (t_list *) malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->content = content;
	new_elem->next = (t_list *) NULL;
	return (new_elem);
}
