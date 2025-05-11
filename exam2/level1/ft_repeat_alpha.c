#include <unistd.h>


int	main(int argc, char *argv[])
{
	char	*str;
	int	i;

	if (argc == 2)
	{
		str = argv[1];
		while (*str)
		{
			if (*str >= 65 && *str <= 90)
			{
				i = 0;
				while (i < (*str - 65 + 1))
				{
					write(1, str, 1);
					i++;
				}
			}

			else if (*str >= 97 && *str <= 122)
			{
				i = 0;
				while (i < (*str - 97 + 1))
				{
					write(1, str, 1);
					i++;
				}
			}
			else
				write(1, str, 1);
			str++;
		}

	}
	write(1, "\n", 1);
	return (0);
}
