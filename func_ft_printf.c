#include <unistd.h>

int    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     ft_putnbr(int i)
{
        long int n;

        n = i;
        if (n < 0)
        {
                n = n * -1;
                write(1, '-', 1);
	}
	if (n > 9)
	{
		ft_putnbr(n/10);	
	}
	n = n % 10;
	n = n + '0';
	write(1, &n, 1);
	
}
