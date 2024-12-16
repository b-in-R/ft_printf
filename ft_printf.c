/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:31:05 by rabiner           #+#    #+#             */
/*   Updated: 2024/12/16 18:25:43 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		ft_putchar((int)*str);
		nb++;
		str++;
	}
	return (nb);
}

int	check_format(char format, va_list ap)
{
	int	nb;

	nb = 0;
	if (format == 'c')
		nb += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		nb += ft_putstr(va_arg(ap, char*));
	else if (format == 'p')
		nb += ft_pnt(va_arg(ap, int));// voir le type pour pointeur
	else if (format == 'd' || format == 'i')
		nb += ft_putnbr(va_arg(ap, int));// recursif, meme que %u, voir pour %x
	else if (format == 'u')
		nb += ft_putnbr(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		nb += ft_putnbr_base(va_arg(ap, int), 16);// recursif, base
	else
		nb += write(1, &format, 1);
	return (nb);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		nb;
	int		i;

	va_start(ap, format);
	nb = 0;
	i = 0;
	while (*format)
	{
		if (*format == '%' && *format + 1 == '%')
		{
			nb += ft_putchar('%');
			format++;
		}
		else if (*format == '%')
			nb += check_format(*(++format), ap);
		else
			nb += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (nb);
}

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
/*
 *	1: trouver le nbre d'apuments grace au %, attention s'il y a %%
 *	2: promotions: si le type n'est pas specifie comme la avec les ..., les char deviennent automatiquement des int
 */


	j = (printf("-----\nVRAI\n-----\nc: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\npct: %%\n", 'a', "test", ptr, 2147483647, -2147483647, 429496729, i, i));

	printf("nbr caract: %i\n", j);

	j = (ft_printf("-----\nTEST\n-----\nc: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\npct: %%\n", 'a', "test", ptr, 2147483647, -2147483647, 429496729, i, i));

	ft_printf("nbr caract: %i\n", j);
	
	return 0;
}
