#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

size_t	ft_strlen(const char *s);
int	ft_putnbr(int i);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_puthexupp(unsigned long i);
int	ft_puthexlow(unsigned long i);
int	ft_putunsigned(unsigned int i);
//static int	convert_format(int sp, va_list *arg);
int	ft_printf(const char *fstr, ...);
#endif
