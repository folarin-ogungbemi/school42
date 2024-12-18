#include "includes/ft_printf.h"
#include "includes/utils.h"

static size_t	ft_check_char(char c, va_list args)
{
	size_t	char_count;

	char_count = 0;
	if (c == 'c')
		char_count += ft_print_char(args);
	if (c == 's')
		char_count += ft_print_str(args);
	if (c == 'p')
		char_count += ft_print_ptr(args);
	if (c == 'd' || c == 'i')
		char_count += ft_print_dec(args);
	if (c == 'u')
		char_count += ft_print_u(args);
	if (c == 'x')
		char_count += ft_print_hexx(args);
	if (c == 'X')
		char_count += ft_print_hexl(args);
	if (c == '%')
		char_count += ft_print_percent();
	return (char_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		char_count;

	va_start(args, format);
	char_count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			char_count += ft_check_char(*(format + 1), args);
			format += 2;
		}
		else
		{
			char_count += ft_putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (char_count);
}
