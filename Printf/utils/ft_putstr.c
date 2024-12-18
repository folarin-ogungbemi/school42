#include "../includes/ft_printf.h"
#include "../includes/utils.h"

size_t	ft_putstr(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
