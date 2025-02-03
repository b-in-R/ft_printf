/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:43:22 by rabiner           #+#    #+#             */
/*   Updated: 2024/12/08 16:43:24 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef __MAC__
#  define NULL_PTR_STR "0x0"
#  define NULL_PTR_LEN 3
# else
#  define NULL_PTR_STR ("(nil)")
#  define NULL_PTR_LEN 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define SYMB_MIN "0123456789abcdef"
# define SYMB_MAX "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	check_format(char format, va_list ap);
int	check_uint(char format, va_list ap);
int	check_ptr(char format, va_list ap);

int	ft_putnbr(long nbr, char format);
int	ft_puthex(unsigned long nbr, char format);

int	ft_putchar(char c);
int	ft_putstr(char *str);

#endif
