/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 18:05:45 by gozturk       #+#    #+#                 */
/*   Updated: 2022/11/11 17:12:31 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int    ft_putchar(char c)
{
    return(write(1, &c, 1));
}
/*
int 	ft_putnbr(int i)
{
	long int n;

	n = i;
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
	}
}*/
static int	convert_format(int sp, va_list arg)
{	
	if (sp == 'c')
			return(ft_putchar(va_arg(arg, int)));
//	if (sp == '%')
}

int	ft_printf(const char *fstr, ...)
{
	va_list	arg;
	int value;
	int	i;
//	int	len;

	value = 0;	
	i = 0;
	va_start(arg, fstr);
	while (fstr[i] != '\0')
	{
		if (fstr[i] == '%')
		{
			i++;
			value += convert_format(fstr[i], arg);
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
	ft_printf("dfagg%c", 'm');
//	printf("\n%c", 'm');
}
