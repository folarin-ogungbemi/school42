#include "../includes/ft_printf.h"
#include "../includes/utils.h"

static size_t	ft_unsigned_recursive(unsigned int nbr)
{
	size_t	count;
	char	digit;

	count = 0;
	if (nbr >= 10)
		count += ft_unsigned_recursive(nbr / 10);
	digit = (nbr % 10) + 48;
	write(1, &digit, 1);
	count++;
	return (count);
}

size_t	ft_unsigned_int(unsigned int nbr)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (ft_unsigned_recursive(nbr));
}
