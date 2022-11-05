/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:34 by satushi           #+#    #+#             */
/*   Updated: 2022/11/05 18:14:13 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

size_t inputnbr(long long subject, char* src)
{
	size_t len;

	len = 0;
	if(subject < 0)
	{
		len = len + ft_putchar('-');
		subject = subject * (-1);
	}
	if(subject < 10)
		len = len + ft_putchar(src[subject]);
    else
	{
		len = len + ft_putaddr_to_hexia(subject / 10, src);
		len = len + ft_putaddr_to_hexia(subject % 10, src);
	}
    return(len);
}

size_t    ft_putnum_to_hexia(unsigned long num, char *basestring)
{
    size_t len;

	len = 0;
	if(num < 16)
		len = len + ft_putchar(basestring[num]);
    else
	{
		len = len + ft_putaddr_to_hexia(num / 16, basestring);
		len = len + ft_putaddr_to_hexia(num % 16, basestring);
	}
    return(len);
}

size_t    ft_putaddr_to_hexia(long long num, char *basestring)
{
	size_t len;

	len = 0;
	if(num < 0)
	{
		len = len + ft_putchar('-');
		num = num * (-1);
	}
	if(num < 16)
		len = len + ft_putchar(basestring[num]);
    else
	{
		len = len + ft_putaddr_to_hexia(num / 16, basestring);
		len = len + ft_putaddr_to_hexia(num % 16, basestring);
	}
    return(len);
}
