/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 18:05:45 by gozturk       #+#    #+#                 */
/*   Updated: 2022/11/14 17:40:08 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i] != '\0')
        {
                i++;
        }
        return (i);
}

int    ft_putchar(char c)
{
    return(write(1, &c, 1));
}

int     ft_putnbr(int i)
{
        long int        n;
        int                     len;

        len = 0;
        n = i;
        if (n < 0)
        {
                n = n * -1;
                write(1, "-", 1);
                len++;
        }
        if (n > 9)
        {
                len += ft_putnbr(n/10);
        }
        n = n % 10;
        n = n + '0';
        len += write(1, &n, 1);
        return (len);
}

int	ft_putstr(char *s)
{
	size_t  len;

	len = ft_strlen(s);
	return(write(1, s, len));
}

int ft_puthexupp(unsigned long i)
{
    int len;

	len = 0;
    if (i > 15)
        len +=  ft_puthexupp(i / 16);
    i = i % 16;
    if (i < 10)
        i += 48;
    else
        i += 'A' - 10;
    return (len + write(1, &i, 1));
}

int ft_puthexlow(unsigned long i)
{
    int len;

	len = 0;
    if (i > 15)
        len +=  ft_puthexlow(i / 16);
    i = i % 16;
    if (i < 10)
        i += 48;
    else
        i += 'a' - 10;
    return (len + write(1, &i, 1));
}

int ft_putunsigned(unsigned int i)
{
    int len;

    len = 0;
    if (i > 10)
        len += ft_putunsigned(i / 10);
    i = i % 10;
    i += '0';
    return (len + write(1, &i, 1));
}

static int	convert_format(int sp, va_list *arg) //NOT PASS BY VALUE :D:D
{	
	if (sp == 'c')
			return(ft_putchar(va_arg(*arg, int)));
	if (sp == 'd')
			return(ft_putnbr(va_arg(*arg, int)));
	if (sp == 'i')
			return(ft_putnbr(va_arg(*arg, int)));
	if (sp == 's')
			return(ft_putstr(va_arg(*arg, char*)));
	if (sp == 'p')
			return(write(1, "0x", 2) + ft_puthexupp(va_arg(*arg, unsigned long)));
	if (sp == 'u')
			return(ft_putunsigned(va_arg(*arg, unsigned)));
	if (sp == 'x')
			return(ft_puthexlow(va_arg(*arg, unsigned long)));
	if (sp == 'X')
			return(ft_puthexupp(va_arg(*arg, unsigned long)));
	if (sp == '%')
			return(ft_putchar('%'));


}

int	ft_printf(const char *fstr, ...)
{
	va_list	arg;
	int value;
	int	i;

	value = 0;	
	i = 0;
	va_start(arg, fstr);
	while (fstr[i] != '\0')
	{
		if (fstr[i] == '%')
		{
			i++;
			value += convert_format(fstr[i], &arg);
		}
		else if (fstr[i] != '%')
			value += ft_putchar(fstr[i]);
		i++;
	}
	va_end(arg);
	return (value); //because orginal f returns some shit
}

int main()
{	
	char a = 'c';
	void *ptrc ;
	ptrc = &a;
//	ft_printf("dfagg_%c%c_gli_%c_%d", 'm', 'x', 't', a);
	ft_printf("%sgulser%d%xivici%p", "gliler", 205, 139, ptrc);
//	printf("\n%c", 'm');
}
