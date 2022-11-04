/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:08 by satushi           #+#    #+#             */
/*   Updated: 2022/11/04 21:29:55 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

static int ft_switch_input(char fmt, va_list args)
{
	if(fmt == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (fmt == '%')
		return (ft_putchar('%'));
	if(fmt == 's')
		return (ft_putchar_string(va_arg(args, char*)));
	if(fmt == 'd' || fmt == 'i')
		return (ft_putnbr_string(va_arg(args, int), "0123456789"));
	if (fmt == 'u')
		return (ft_putaddr_to_hexia(va_arg(args, unsigned int), "0123456789abcdef"));
	if (fmt == 'p')
		return (ft_putaddr_to_hexia(va_arg(args, long long), "0123456789abcdef"));
	if (fmt == 'x')
		return (ft_putnum_to_hexia(va_arg(args, unsigned long), "0123456789abcdef"));
	if (fmt == 'X')
		return (ft_putnum_to_hexia(va_arg(args, unsigned long), "0123456789ABCDEF"));
}

int ft_printf(const char *fmt_or_nch, ...)
{
	va_list args;
	long long counter;

	counter = 0;
	va_start(args, fmt_or_nch);
	while(*fmt_or_nch != '\0')
	{
		if(*fmt_or_nch == '%')
		{
			counter = counter + ft_switch_input(*(fmt_or_nch + 1), args);
			fmt_or_nch = fmt_or_nch + 2;
		}
		else
		{
			ft_putchar((char)(*fmt_or_nch));
			if(*fmt_or_nch == '\0')
				break ;
			fmt_or_nch = fmt_or_nch + 1;
			counter = counter + 1;
		}
	}
	va_end(args);
	return counter;
}
