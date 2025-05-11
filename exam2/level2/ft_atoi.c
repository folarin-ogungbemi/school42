#include <unistd.h>
#include <stdio.h>

int	ft_isspace(int c)
{
	if (c >= 9 && c <= 13 || c == 32)
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
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
		num = num * 10 + (*str - 48);
		str++;
	}
	return (num * sign);
}	

int	main(int ac, char *av[])
{
	char	*str;
	int	nbr;

	if (ac == 2)
	{
		nbr = ft_atoi(av[1]);
		printf("result: %d\n", nbr);
	}
	write(1, "\n", 1);
	return (0);
}
