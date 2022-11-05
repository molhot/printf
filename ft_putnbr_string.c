/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:34 by satushi           #+#    #+#             */
/*   Updated: 2022/11/05 17:59:08 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

size_t inputnbr(long long subject, char* src)
{
	long long subject_dig;
	size_t len;

	subject_dig = 1;
	len = 0;
	while(subject_dig <= subject)
		subject_dig = subject_dig * 10;
	subject_dig = subject_dig / 10;
	if(subject < 0)
	{
		subject = subject * (-1);
		len = len + ft_putchar('-');
	}
	while(subject_dig != 0)
	{
		len = len + ft_putchar(src[subject / subject_dig]);
		subject = subject % subject_dig;
		subject_dig = subject_dig / 10;
	}
	return len;
}

size_t    ft_putnum_to_hexia(unsigned long num, char *basestring)
{
    int max_divited_counter;
    char *addr_box;
	size_t len;

    max_divited_counter = ft_divide_max(num, 16);
    addr_box = (char *)malloc(sizeof(char) * (max_divited_counter + 1));
    addr_box[max_divited_counter - 1] = '\0';
    max_divited_counter--;
    while(max_divited_counter != 0)
    {
        addr_box[max_divited_counter] = basestring[num % 16];
        num = num / 16;
        max_divited_counter--;
    }
    addr_box[max_divited_counter] = basestring[num];
	len = 0;
	len = len + ft_putchar_string(addr_box);
	free(addr_box);
    return (len);
}

size_t    ft_putaddr_to_hexia(long long num, char *basestring)
{
    char *addr_box;
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
