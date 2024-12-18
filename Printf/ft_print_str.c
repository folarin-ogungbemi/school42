#include "includes/ft_printf.h"
#include "includes/utils.h"

size_t	ft_print_str(va_list args)
{
	const char	*value;
	size_t		char_count;

	char_count = 0;
	value = va_arg(args, const char *);
	if (!value)
		value = "(null)";
	char_count += ft_putstr(value);
	return (char_count);
}
