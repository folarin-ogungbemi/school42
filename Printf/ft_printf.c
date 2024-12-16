#include "includes/ft_printf.h"
#include "includes/utils.h"

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	i;
	int	char_count;
	char	x;
	int	value;
	unsigned int	u_int;
	void	*ptr;
	const char	*str;

	va_start(args, format);
	i = 0;
	char_count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			x = va_arg(args, int);
			char_count += ft_putchar(x);
			i+=2;
		}
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			value = va_arg(args, int);
			char_count += ft_putnbr(value);
			i+=2;
		}
		if (format[i] == '%' && format[i + 1] == 'u')
		{
			u_int = va_arg(args, unsigned int);
			char_count += ft_unsigned_int(u_int);
			i+=2;
		}
		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, "%", 1);
			char_count ++;
			i+=2;
		}
		if (format[i] == '%' && format[i + 1] == 'p')
		{
			ptr = va_arg(args, void *);
			char_count += ft_pointer(ptr);
			i+=2;
		}
		if (format[i] == '%' && format[i + 1] == 'x')
		{
			value = va_arg(args, int);
			char_count += ft_hexdec_low(value);
			i+=2;
		}
		if (format[i] == '%' && format[i + 1] == 'X')
		{
			value = va_arg(args, int);
			char_count += ft_hexdec_high(value);
			i+=2;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(args, const char *);
			char_count += ft_putstr(str);
			i+=2;
		}
		else
		{
			char_count += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (char_count);
}
