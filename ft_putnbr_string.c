/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:34 by satushi           #+#    #+#             */
/*   Updated: 2022/11/05 13:36:03 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

static int counter_digit(const char *base_num)
{
	int digit;

	digit = 0;
	while(*base_num != '\0')
	{
		digit = digit + 1;
		base_num = base_num + 1;
	}
	return digit;
}

static int num_base(int subject_num, int base_num)
{
	int malloc_size;

	malloc_size = 0;
	if(subject_num == 0)
		return (1);
	if(subject_num < 0)
	{
		malloc_size = malloc_size + 1;
		subject_num = subject_num * (-1);
	}
	while(subject_num != 0)
	{
		malloc_size = malloc_size + 1;
		subject_num = subject_num / base_num;
	}
	return malloc_size;
}

static char *inputnbr(int subject, int base, int size)
{
	char *char_malloc;
	char p_m;

	char_malloc = (char *)malloc(sizeof(char) * size);
	if(char_malloc == NULL)
		return (NULL);
	char_malloc[size - 1] = '\0';
	size = size - 1;
	if(subject < 0)
	{
		subject= subject * -1;
		char_malloc[0] = '-';
		p_m = 'm';
	}
	else
		p_m = 'p';
	while(size != 0)
	{
		size = size - 1;
		char_malloc[size] = subject % base + '0';
		if(size == 1 && p_m == 'm')
			break ;
		subject = subject / base;
	}
	return char_malloc;
}
