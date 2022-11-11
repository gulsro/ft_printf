#include <unistd.h>
#include <stdio.h>

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
		len += write(1, "-", 1);
	}
	if (n > 9)
	{
//		len += ft_putnbr(n/10);
		ft_putnbr(n/10);
	}
	n = n % 10;
	n = n + '0';
	len++;
	write(1, &n, 1);
//	return(write(1, &n, 1));
//	return (len + write(1, &n, 1));
	return (len);
}

int main()
{
//	int a;
	int i = -6543;
//	a = ft_putnbr(i);
	printf("\n%d\n", ft_putnbr(i));
	ft_putnbr(i);
}
