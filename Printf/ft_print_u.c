#include "includes/ft_printf.h"
#include "includes/utils.h"

size_t	ft_print_u(va_list args)
{
	unsigned int	value;
	size_t			char_count;

	char_count = 0;
	value = va_arg(args, unsigned int);
	char_count += ft_unsigned_int(value);
	return (char_count);
}
