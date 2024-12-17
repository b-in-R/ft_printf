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

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>////
# include <limits.h>///

# define SYMB_MIN "0123456789abcdef"
# define SYMB_MAX "0123456789ABCDEF"

int	ft_printf(const char *format, ...);

#endif
