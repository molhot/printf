/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:52 by satushi           #+#    #+#             */
/*   Updated: 2022/11/05 11:52:33 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

size_t ft_putchar(char inputchar_num)
{
	write(1, &inputchar_num, 1);
	return (1);
}

size_t ft_putchar_string(char *sub_string)
{
	int counter ;

	counter = 0;
	while(*sub_string != '\0')
	{
		ft_putchar(*sub_string);
		sub_string = sub_string + 1;
		counter = counter + 1;
	}
	return (counter);
}

size_t ft_divide_max(long long num, int divide_num)
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