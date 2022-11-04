/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_to_hexia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:52 by satushi           #+#    #+#             */
/*   Updated: 2022/11/04 20:36:36 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_print.h"

void    ft_putnum_to_hexia(unsigned long num, char *basestring)
{
    int max_divited_counter;
    char *addr_box;

    if(num < 0)
    {
        ft_putchar('-');
        num = num * (-1);
    }
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
}
