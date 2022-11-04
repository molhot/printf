/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:52 by satushi           #+#    #+#             */
/*   Updated: 2022/11/04 20:10:44 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void ft_putchar(char inputchar_num)
{
	write(1, &inputchar_num, 1);
}

void ft_putchar_string(char *sub_string)
{
	while(*sub_string != '\0')
	{
		ft_putchar(*sub_string);
		sub_string = sub_string + 1;
	}
}

int ft_divide_max(long long num, int divide_num)
{
    int counter;

    counter = 0;
    while(num != 0)
    {
        num = num / divide_num;
        counter = counter + 1;
    }
    return (counter);
}