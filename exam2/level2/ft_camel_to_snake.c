#include <unistd.h>

int	main(int ac, char *av[])
{
	char	*str;
	char	c;

	if (ac == 2)
	{
		str = av[1];
		while (*str)
		{
			if (*str >= 65 && *str <= 90)
			{
				c = *str + 32;
				write(1, "_", 1);
				write(1, &c, 1);
			}
			else
				write(1, str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
