#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
//	const char str[100];
	va_list	args;
	va_start(args, str);
//	int	len;
	int	i;
	char c;
	
	i = 0;
//	len = strlen(str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
		}
		else if (*str == 'c')
		{
			c = va_arg(args, char);
			write(1, &c, 1);
		}
	//	i++;
	}
	va_end(args);
	return 0;
}

int main()
{		
	char my_char = 'k';
	ft_printf("%c", my_char);
//	printf("\n%c", my_char);
}
