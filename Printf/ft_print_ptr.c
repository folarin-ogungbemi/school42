#include "includes/ft_printf.h"
#include "includes/utils.h"

size_t	ft_print_ptr(va_list args)
{
	void	*value;
	size_t	char_count;

	char_count = 0;
	value = va_arg(args, void *);
	char_count += ft_pointer(value);
	return (char_count);
}
