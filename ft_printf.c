/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:08 by satushi           #+#    #+#             */
/*   Updated: 2022/11/05 14:23:44 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void ft_switch_input(char fmt, va_list args, size_t *counter)
{
	if(fmt == 'c')
		*counter = *counter + ft_putchar(va_arg(args, int));
	else if (fmt == '%')
		*counter = *counter + (ft_putchar('%'));
	else if(fmt == 's')
		*counter = *counter + ft_putchar_string(va_arg(args, char*));
	else if(fmt == 'd' || fmt == 'i')
		*counter = *counter + ft_putnbr_string(va_arg(args, int), "0123456789");
	else if (fmt == 'u')
		*counter = *counter + ft_putnbr_string(va_arg(args, unsigned int), "0123456789");
	else if (fmt == 'p')
	{
		*counter = *counter + ft_putchar_string("0x");
		*counter = *counter + ft_putaddr_to_hexia(va_arg(args, unsigned long long), "0123456789abcdef");
	}
	else if (fmt == 'x')
		*counter = *counter + ft_putnum_to_hexia(va_arg(args, long long), "0123456789abcdef");
	else if (fmt == 'X')
		*counter = *counter + ft_putnum_to_hexia(va_arg(args, long long), "0123456789ABCDEF");
}

int ft_printf(const char *fmt_or_nch, ...)
{
	va_list args;
	size_t counter;

	counter = 0;
	va_start(args, fmt_or_nch);
	while(*fmt_or_nch != '\0')
	{
		if(*fmt_or_nch == '%')
		{
			ft_switch_input(*(fmt_or_nch + 1), args,&counter);
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
	return (int)counter;
}
