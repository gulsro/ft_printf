#include <unistd.h>
#include <stdio.h>

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
    return (write(1, &c, 1));
}

int     ft_putnbr(int i)
{	
	long int	n;
	int			len;

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

int	ft_putstr_fd(char *s)
{	
	size_t  len;

	len = ft_strlen(s);
	return (write(1, s, len));
}

int puthexa_low(int )
int main()
{
	int i = 54;
	printf("\n%d\n", ft_putnbr(i));
//	ft_putnbr(i);
}
