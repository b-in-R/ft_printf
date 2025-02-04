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


#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int		j = 0;
	int		k = 0;


	char	c = 'B';
	char	str[] = "chevre";
	int		num1 = -2345;
	int		num2 = 3049243;
	int		num3 = -2147483647;
	unsigned int	unum = 345676543;

	j = (ft_printf("TEST\n-----\nc: %c\ns: %s\np: %p\np: %p\nd: %d\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\ni: %i\n%%\n",
		c, str, &str, NULL, num1, num2, num3, unum, num2, num2, num1));
	ft_printf("ft_nbr caract: %i\n", j);
	printf("vr_nbr caract: %i\n-----------\n", j);
	k = (printf("VRAI\n-----\nc: %c\ns: %s\np: %p\np: %p\nd: %d\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\ni: %i\n%%\n",
		c, str, &str, NULL, num1, num2, num3, unum, num2, num2, num1));
	ft_printf("ft_nbr caract: %i\n", k);
	printf("vr_nbr caract: %i\n----------\n", k);

	return (0);
}

