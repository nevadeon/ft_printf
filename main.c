/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:00:55 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/08 17:01:40 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <assert.h>

int	main(void)
{
	int *ptr = (int *) malloc(sizeof(int));

	assert(printf("") == ft_printf(""));
	assert(printf("Hello world!\n") == ft_printf("Hello world!\n"));
	assert(printf("%char\n", 'c') == ft_printf("%char\n", 'c'));
	assert(printf("%s", "string\n") == ft_printf("%s", "string\n"));
	assert(printf("%p pointer\n", ptr) == ft_printf("%p pointer\n", ptr));
	assert(printf("%d school\n", 42) == ft_printf("%d school\n", 42));
	assert(printf("%i is a great number\n", 69) == ft_printf("%i is a great number\n", 69));
	assert(printf("%u\n", 4354538) == ft_printf("%u\n", 4354538));
	assert(printf("%x\n", 4354538) == ft_printf("%x\n", 4354538));
	assert(printf("%X\n", 4354538) == ft_printf("%X\n", 4354538));
	assert(printf("%%%%%%%%\n") == ft_printf("%%%%%%%%\n"));

	return (0);
}
