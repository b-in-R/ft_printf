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

#include "ft_printf.h"

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

int	ft_puthex(unsigned int nbr, char format)
{
	int	nb;

	if (nbr == 0)
		return (write(1, "0", 1));
	else if (nbr >= 16)
	{
		ft_puthex(nbr / 16, format);
		return (nb + ft_puthex(nbr % 16, format));
	}
	else if (nbr <= 9)
		return (ft_putchar(nbr + 48));
	else if (format == 'X')
		return (ft_putchar(SYMB_MAX[nbr]));
	else
		return (ft_putchar(SYMB_MIN[nbr]));
}

int	ft_putnbr(int nbr, char format)
{
	int		nb;
	
	if (format == 'u')
		nbr = (unsigned int)nbr;
	if (nbr == -2147483648 && (format == 'i' || format == 'd'))
	{
		return (nb = write(1, "-2147483648", 11));
	}
	if (nbr < 0 && (format == 'i' || format == 'd'))
	{
		nb = write(1, "-", 1);
		return (ft_putnbr(-nbr, format) + 1);
	}
	else if (nbr > 9)
	{
		nb = ft_putnbr(nbr / 10, format);
		return (nb + ft_putnbr(nbr % 10, format));
	}
	else
		return (ft_putchar(nbr + 48));
}

int	check_format(char format, va_list ap)
{
	int	nb;

	nb = 0;
	if (format == 'c')
		nb += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		nb += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
	{
		nb += write(1, "0x", 2);
		nb += ft_puthex(va_arg(ap, unsigned int), format);
	}
	else if (format == 'd' || format == 'i')
		nb += ft_putnbr(va_arg(ap, int), format);
	else if (format == 'u')
		nb += ft_putnbr(va_arg(ap, unsigned int), format);
	else if (format == 'x' || format == 'X')
		nb += ft_puthex(va_arg(ap, unsigned int), format);
	else
		nb += write(1, &format, 1);
	return (nb);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		nb;

	va_start(ap, format);
	nb = 0;
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
	int		k = 0;
	char	p[]= "salut";

	j = (ft_printf("TEST\n----\n%p\n", p));
	ft_printf("test caract: %i\n", j);
	printf("vrai caract: %i\n-----------------\n\n", j);

	k = (printf("VRAI\n----\n%p\n", p));
	ft_printf("test caract: %i\n", k);
	printf("vrai caract: %i\n-----------------\n", k);
/*
	%c -> char								ok
	%s -> string							ok
	%p -> void * pointer en hexadecimal		!  marche pas
	%d -> decimal (base 10)					ok
	%i -> integer (base 10)					ok
	%u -> unsigned decimal nbr (base 10)	!  chiffres neg
	%x -> nbr en hexa (base 16) lowercase	ok
	%X -> nbr en hexa (base 16) uppercase	ok
	%% -> pourcent sign						ok
*/
/*
 *	1: trouver le nbre d'apuments grace au %, attention s'il y a %%
 *	2: promotions: si le type n'est pas specifie comme la avec les ..., les char deviennent automatiquement des int
 */
/*
	j = (printf("-----\nVRAI\n-----\nc: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\npct: %%\n", 'a', "test", ptr, 2147483647, -2147483647, 429496729, i, i));

	printf("nbr caract: %i\n", j);

	k = (ft_printf("-----\nTEST\n-----\nc: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\npct: %%\n", 'a', "test", ptr, 2147483647, -2147483647, 429496729, i, i));

	ft_printf("nbr caract: %i\n", k);
	printf("(v)nbr caract: %i\n", k);
*/
//	j = (printf("-----\nVRAI\n-----\np: %p\nx: %x\nX: %X\n", ptr, i, i));

//	printf("nbr caract: %i\n", j);

//	k = (ft_printf("-----\nTEST\n-----\np: %p\nx: %x\nX: %X\n", ptr, i, i));
	return 0;
}
