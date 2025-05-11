#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*str;
	char	x;

	if (argc == 2)
	{
		str = argv[1];
		while (*str)
		{
			if (*str >= 65 && *str <= 90)
			{
				x = *str + 32;
				write(1, &x, 1);
			}
			else if (*str >= 97 && *str <= 122)
			{
				x = *str - 32;
				write(1, &x, 1);
			}
			else
				x = *str;
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
