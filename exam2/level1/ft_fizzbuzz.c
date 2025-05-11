#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + 48;
	write(1, &c, 1);
}

int	main(void)
{
	int	min;
	int	max;

	min = 1;
	while (min <= 100)
	{
		if (min % 3 == 0 && min % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (min % 3 == 0)
			write(1, "fizz", 4);
		else if (min % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(min);
		write(1, "\n", 1);
		min++;
	}
	return (0);
}
	
