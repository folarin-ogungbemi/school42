#include "includes/ft_printf.h"
#include "includes/utils.h"

size_t	ft_print_percent(void)
{
	size_t	char_count;

	char_count = 0;
	write(1, "%", 1);
	char_count ++;
	return (char_count);
}
