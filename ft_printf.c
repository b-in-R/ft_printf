/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:31:05 by rabiner           #+#    #+#             */
/*   Updated: 2024/12/08 16:31:08 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		nb;

	nb = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if(*format == 'c')
			{

			}
			else if(*format == 's')
			{

			}
			else if(*format == 'p')
			{

			}
			else if(*format == 'd' || *format == 'i' || *format == 'u')
			{

			}
			else if(*format == 'x' || *format == 'X')
			{

			}
			else if(*format == %)
			{

			}
		}
		else
		{
			ft_putchar(*format);
			nb++;
		}
		format++;
	}
	va_end(arg);
	return (nb);
}

#include <stdio.h>
int	main(void)
{
	int		i = 45;
	int		j = 0;
	int		*ptr = &i;
/*
	%c -> char
	%s -> string
	%p -> void * pointer en hexadecimal
	%d -> decimal (base 10)
	%i -> integer (base 10)
	%u -> unsigned decimal nbr (base 10)
	%x -> nbr en hexa (base 16) lowercase
	%X -> nbr en hexa (base 16) uppercase
	%% -> pourcent sign
*/
	j = (printf("-----\nVRAI\n-----\nc: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\npct: %%\n", 'a', "test", ptr, 2147483647, -2147483647, 429496729, i, i));
	printf("nbr caract: %i\n", j);
	j = (ft_printf("-----\nTEST\n-----\nc: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\npct: %%\n", 'a', "test", ptr, 2147483647, -2147483647, 429496729, i, i));
	ft_printf("nbr caract: %i\n", j);
	
	return 0;
}
