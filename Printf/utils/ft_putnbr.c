#include "../includes/ft_printf.h"

size_t	ft_putnbr(int nbr)
{
	char	digit;
	size_t	count;

	count = 1;
	if (nbr == INT_MIN)
	{
		write(1, "-2147483648", 12);
		return (11);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		count++;
	}
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	digit = (nbr % 10) + 48;
	write(1, &digit, 1);
	return (count);
}
