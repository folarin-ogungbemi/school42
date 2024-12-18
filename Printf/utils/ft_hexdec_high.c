#include "../includes/ft_printf.h"
#include "../includes/utils.h"

static size_t	ft_hex_recursive(unsigned int nbr, const char *base)
{
	size_t	count;
	size_t	len;

	len = ft_strlen(base);
	count = 0;
	if (nbr >= len)
		count += ft_hex_recursive(nbr / len, base);
	ft_putchar(base[nbr % len]);
	count++;
	return (count);
}

size_t	ft_hexdec_high(int nbr)
{
	char			base[17];
	unsigned int	u_nbr;

	ft_strcpy(base, "0123456789ABCDEF");
	if (nbr < 0)
		u_nbr = (unsigned int)nbr;
	else
		u_nbr = nbr;
	return (ft_hex_recursive(u_nbr, base));
}
