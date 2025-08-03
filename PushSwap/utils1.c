#include "push_swap.h"

int	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (1);
}

static int	ft_isdigit(char c)
{
	return (c >= 48 && c <= 57);
}

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - 48);
		if ((sign == 1 && nbr > 2147483647)
			|| (sign == -1 && nbr > 2147483648))
			exit_error();
		str++;
	}
	return (nbr * sign);
}
