#include <unistd.h>
#include <stdio.h>

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isspace(char	c)
{
	if (c == 32 || c >= 7 && c <= 13)
		return (1);
	return (0);
}
/*
int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
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
*/	
int	main(int ac, char *av[])
{
	int	result;

	if (ac == 4)
	{
		if (av[2][0] == '+')
		{
			result = ft_atoi(av[1]) + ft_atoi(av[3]);
			printf("result %d\n", result);
		}
	}
	write(1, "\n", 1);
	return (0);
}
