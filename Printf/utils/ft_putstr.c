#include "../includes/ft_printf.h"
#include "../includes/utils.h"

size_t	ft_putstr(const char *str)
{
	size_t	str_len;

	str_len = ft_strlen(str); 
	write(1, str, str_len);
	return (str_len);
}
