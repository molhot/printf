/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:52 by satushi           #+#    #+#             */
/*   Updated: 2022/11/05 18:52:20 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

size_t ft_putchar(char inputchar_num)
{
	return (write(1, &inputchar_num, 1));
}

size_t ft_putchar_string(char *sub_string)
{
	size_t len;

	if(sub_string == NULL)
		return 6;
	len = 0;
	while(sub_string[len] != '\0')
		len = len + 1;
	return (write(1, sub_string, len));
}