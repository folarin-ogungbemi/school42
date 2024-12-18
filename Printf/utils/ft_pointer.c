#include "../includes/ft_printf.h"
#include "../includes/utils.h"

static size_t	ft_hex_recursive(size_t address, char *base)
{
	size_t	len;
	size_t	count;
	char	digit;

	count = 0;
	len = ft_strlen(base);
	if (address >= len)
		count += ft_hex_recursive(address / len, base);
	digit = base[address % len];
	write(1, &digit, 1);
	count++;
	return (count);
}

size_t	ft_pointer(void *ptr)
{
	unsigned long	address;
	char			base[17];
	size_t			count;

	count = 0;
	address = (unsigned long)ptr;
	ft_strcpy(base, "0123456789abcdef");
	if (!address)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	count += 2;
	if (address > 0)
		count += (ft_hex_recursive(address, base));
	else
		count += write(1, "0", 1);
	return (count);
}
