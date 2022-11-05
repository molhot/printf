/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_to_hexia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:52 by satushi           #+#    #+#             */
/*   Updated: 2022/11/05 11:57:23 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_print.h"

size_t    ft_putnum_to_hexia(unsigned long num, char *basestring)
{
    int max_divited_counter;
    char *addr_box;

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
    return(ft_putchar_string(addr_box));
}
