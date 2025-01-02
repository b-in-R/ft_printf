/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:31:05 by rabiner           #+#    #+#             */
/*   Updated: 2024/12/16 18:25:43 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		i;
	int		j;
	int		*p;

	i = 8;
	j = 0;
	p = &i;
	j = (ft_printf("TEST\n----\n1.\nc: %c\ns: %s\np: %p\n", 'a', "che", p));
	j += (ft_printf("2.\nd: %d\ni: %i\nu: %u\n", i, -2147483648, -i));
	j += (ft_printf("3.\nx: %x\nX: %X\n%%\n", p, p));
	ft_printf("nbr caract: %i\n", j);
	return (0);
}
/*
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int		i = 8;
	int		j = 0;
	int		k = 0;
	int		*p = &i;
//	char	str[] = NULL;

	j = (ft_printf("TEST\n-----\n24.long max: %u\n27.ulong max: %u\
			\n28.92..07LL: %u\n", LONG_MAX, ULONG_MAX, 9223372036854775807LL));
	ft_printf("ft_nbr caract: %i\n", j);
	printf("vr_nbr caract: %i\n-----------\n", j);
	k = (printf("VRAI\n-----\n24.long max: %lu\n27.ulong max: %lu\
		\n28.92..07LL: %llu\n", LONG_MAX, ULONG_MAX, 9223372036854775807LL));
	ft_printf("ft_nbr caract: %i\n", k);
	printf("vr_nbr caract: %i\n----------\n", k);

	k++;
	p++;
	return (0);
}
*/
