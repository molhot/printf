#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int 	ft_printf(const char *fmt_or_nch, ...);
void	ft_putnbr_string(int subject_num, const char *base_char);
int	ft_putchar(char inputchar_num);
int	ft_putchar_string(char *sub_string);
char	*ft_strdup(const char *s);
int    ft_putaddr_to_hexia(long long num, char *basestring);
int    ft_putnum_to_hexia(unsigned long num, char *basestring);
int     ft_divide_max(long long num, int divide_num);

#endif
