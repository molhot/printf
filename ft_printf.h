/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:22:59 by satushi           #+#    #+#             */
/*   Updated: 2022/11/11 20:32:39 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fmt_or_nch, ...);
size_t	ft_putchar(char inputchar_num);
size_t	ft_putchar_string(char *sub_string);
size_t	ft_putaddr_to_hexia(unsigned long long num, char *basestring);
size_t	ft_putnum_to_hexia(long long num, char *basestring);
size_t	inputnbr(long long subject, char *src);

#endif
