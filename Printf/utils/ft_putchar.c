#include "../includes/ft_printf.h"
#include "../includes/utils.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
