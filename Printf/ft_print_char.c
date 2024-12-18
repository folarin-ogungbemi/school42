#include "includes/ft_printf.h"
#include "includes/utils.h"

size_t	ft_print_char(va_list args)
{
	char	value;
	size_t	char_count;

	char_count = 0;
	value = va_arg(args, int);
	char_count += ft_putchar(value);
	return (char_count);
}
