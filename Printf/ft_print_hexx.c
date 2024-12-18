#include "includes/ft_printf.h"
#include "includes/utils.h"

size_t	ft_print_hexx(va_list args)
{
	int		value;
	size_t	char_count;

	char_count = 0;
	value = va_arg(args, int);
	char_count += ft_hexdec_low(value);
	return (char_count);
}
