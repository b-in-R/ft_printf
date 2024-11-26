

#include "libftprintf.h"
#include <stdio.h>//
#include <unistd.h>
#include <stdarg.h>

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
			if(*format == 'd')
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

int	main(void)
{
	char	c = 'a';
	char	str[] = "str";
	int		i = 45;
	

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

}
