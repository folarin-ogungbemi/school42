#include "../includes/ft_printf.h"
#include "../includes/utils.h"

size_t	ft_hexdec_low(int nbr)
{
	size_t	count;
	char	base[17];
	int	len;
	
	ft_strcpy(base, "0123456789abcdef");
	len = ft_strlen(base);
	count = 1;
	if (nbr < 0)
		return (0);
	if (nbr >= len)
		count += ft_hexdec_low(nbr / len);
	ft_putchar(base[nbr % len]);
	return (count);
}
