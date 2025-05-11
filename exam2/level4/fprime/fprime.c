#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	fprime(int nbr)
{
	int	i;
	int	sign;

	i = 2;
	sign = 0;
	while (nbr > 1)
	{
		if (nbr % i == 0)
		{
			if (sign)
				printf("%c", '*');
			printf("%d", i);
			sign = 1;
			nbr /= i;
		}
		else
			i++;
	}
	printf("\n");
}

int	main(int ac, char *av[])
{
	char	*str;

	if (ac == 2)
	{
		str = av[1];
		fprime(atoi(str));
		return (0);
	}
	write (1, "\n", 1);
	return (0);
}
