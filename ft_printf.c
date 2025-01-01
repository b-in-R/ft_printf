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

int	ft_puthex(unsigned long nbr, char format)
{
	int	nb;

	if (nbr == 0)
		return (write(1, "0", 1));
	else if (nbr >= 16)
	{
		nb = ft_puthex(nbr / 16, format);
		return (nb + ft_puthex(nbr % 16, format));
	}
	else if (nbr <= 9)
		return (ft_putchar(nbr + 48));
	else if (format == 'X')
		return (ft_putchar(SYMB_MAX[nbr]));
	else
		return (ft_putchar(SYMB_MIN[nbr]));
}

int	ft_putnbr(long nbr, char format)
{
	int		nb;

	if (format == 'u' && nbr < 0)
		nbr = (unsigned long)nbr;
	if (nbr == -2147483648 && (format == 'i' || format == 'd'))
		return (nb = write(1, "-2147483648", 11));
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

int	check_ptr(char format, va_list ap)
{
	void	*ptr;
	int		nb;

	nb = 0;
	ptr = va_arg(ap, void *);
	if (ptr == NULL)
		nb += write(1, "(nil)", 5);
	else
	{
		nb += write(1, "0x", 2);
		nb += ft_puthex((unsigned long)ptr, format);
	}
	return (nb);
}

int	check_format(char format, va_list ap)
{
	int		nb;

	nb = 0;
	if (format == 'c')
		nb += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		nb += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		nb += check_ptr(format, ap);
	else if (format == 'd' || format == 'i')
		nb += ft_putnbr(va_arg(ap, int), format);
	else if (format == 'u')
		nb += ft_putnbr(va_arg(ap, unsigned long), format);
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
		if (*format == '%' && *(format + 1) == '%')
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
/*
int	main(void)
{
	int		i = 8;
	int		j = 0;
	int		k = 0;
	int		*po = 0;
	char	p[]= "salut";

	j = (ft_printf("TEST\n----\n%p\non ecrit un truc\n%p\n%i\n%s\n%u\n%u\n",
		po, p, i, p, i, -i));
	ft_printf("test caract: %i\n", j);
	printf("vrai caract: %i\n-----------------\n\n", j);

	k = (printf("VRAI\n----\n%p\non ecrit un truc\n%p\n%i\n%s\n%u\n%u\n",
		po, p, i, p, i, -i));
	ft_printf("test caract: %i\n", k);
	printf("vrai caract: %i\n-----------------\n", k);

	return 0;
}
*/
