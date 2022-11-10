/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 18:05:45 by gozturk       #+#    #+#                 */
/*   Updated: 2022/11/10 18:34:20 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int    ft_putchar_fd(char c)
{
    write(1, &c, 1);
	return (1);
}

static int	convert_format(int sp, va_list arg)
{	
	if (sp == 'c')
			return(ft_putchar_fd(va_arg(arg, int)));
//	if (sp == '%')
}

int	ft_printf(const char *fstr, ...)
{
	va_list	arg;
	int c;
	int	i;
	int	len;
	
	i = 0;
	va_start(arg, fstr);
	while (fstr[i] != '\0')
	{
		if (fstr[i] == '%')
		{
			i++;
			c = convert_format(fstr[i], arg);
		}
		else if (fstr[i] != '%')
			c = ft_putchar_fd(fstr[i]);
	}
	va_end(arg);
	return (c);
}

int main()
{	
	int	i;

	i = printf("hello");
	printf("\n i = %d", i);	
	//ft_printf("%c", 'm');
//	printf("\n%c", 'm');
//
}
