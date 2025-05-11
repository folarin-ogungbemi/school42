#include <unistd.h>

int	main(int argc, char *argv[])
{
	char *str;
	char	x;

	if (argc == 2)
	{
		str = argv[1];
		while (*str)
		{
			if (*str >= 65 && *str <= 90)
			{	
				if ((*str - 65) < 13)
					x = *str + 13;
				else
					x = *str - 13;
				write(1, &x, 1);
			}
			else if (*str >= 97 && *str <= 122)
			{	
				if ((*str - 97) < 13)
					x = *str + 13;
				else
					x = *str - 13;
				write(1, &x, 1);
			}
			else
				write(1, str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
